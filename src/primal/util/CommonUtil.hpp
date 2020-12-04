#pragma once

#include "../../Vendor.hpp"

class CommonUtil {

public:

    //Common math.
    #define IN_RANGE(x,a,b)	(x >= a && x <= b)
    #define GET_BITS(x)		(IN_RANGE (x,'0','9') ? (x - '0') : ((x&(~0x20)) - 'A' + 0xA))
    #define GET_BYTE(x)		(GET_BITS (x[0]) << 4 | GET_BITS (x[1]))

    /**
     *
     * @point - Get module base address from internal process.
     *
     * @args  - Module: Module name.
     *
     **/

    static HMODULE GetModule (const char* module);

    /**
     *
     * @point - Get module info from internal process.
     *
     * @args  - Module: Module name.
     *
     **/

    static MODULEINFO GetModuleInfo (const char* module);

    /**
     *
     * @point - Get function address from module.
     *
     * @args  - Module: Module name. Function - Function name.
     *
     **/

    static FARPROC GetOrLoadFunction (const char* module, const char* function);

    /**
     *
     * @point - Search signature in module memory space.
     *
     * @args  - Module: Module name. Signature: IDA-styled signature.
     *
     **/

    static int SearchSignature (const char *module, const char* signature);

};