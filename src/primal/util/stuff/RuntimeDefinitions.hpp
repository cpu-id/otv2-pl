#pragma once

#include "../../../Vendor.hpp"

namespace AdditionalRuntime {

    //Original entry point/DllMain template.
    //Docs: https://docs.microsoft.com/en-us/windows/win32/dlls/dllmain.
    typedef BOOL (__stdcall* DllMain) (HMODULE hModule, DWORD callReason, LPVOID lpReserved);

    struct AllocaParameters {

        //Allocation base address.
        int m_base = 0x0;

        //Allocation size. (Must be bigger than segment size)
        int m_size;

        //Allocation type.
        int m_type = MEM_COMMIT | MEM_RESERVE;

        //Page protect type.
        int m_protect = PAGE_EXECUTE_READWRITE;

    };

    enum ImportType {

        //Can be presented as LEA or MOV.
        //
        //Example [0]: lea $register, [$function]
        //Example [1]: mov $register, [$function]
        //
        INTERNAL,

        //Can be presented as JMP or CALL.
        //
        //Example [0]: jmp $function
        //Example [1]: call $function
        //
        PUBLIC

    };

    struct ImportDefinition {

        //Import function name.
        std::string m_function;

        //RVA's of function.
        //
        //   MAP VIEW:
        //
        //        ImportType ->
        //                      RVA
        //
        std::map <ImportType, std::vector <unsigned int>> m_relocations;

    };

    struct RelocationDefinition {

        //Old alloca base for subtract absolute relocation.
        int m_oldAllocationBase;

        //Relocation array pointer.
        int* m_relocations;

        //Relocations size.
        int m_relocationCount;

    };

};

//Primal region: "Alloc".
namespace Primal {

    //Global allocation parameters. (Based on segment parameters)
    extern AdditionalRuntime::AllocaParameters AllocParameters;

}