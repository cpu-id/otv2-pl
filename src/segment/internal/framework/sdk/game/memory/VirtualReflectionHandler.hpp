#pragma once

#include "../../../../../../Vendor.hpp"

namespace OneSDK {

    namespace MemoryController {

        namespace HookData {

            //Just offset to function for hook it.
            extern INT CallVirtualFunction__OffsetToHook;

        };

        /**
         *
         * @point - Call virtual function from interface.
         * @args  - Vtable: Pointer to interface virtual table. Index: Function index.
         *
         * @reversed -
         * {
         *
         *  int __fastcall C_SDK::VirtualReflectionHandler::CallVirtualFunction (int *interface, int index)
         *
         *      //Virtual function address.
         *      int result;
         *
         *      //Is interface, pointer to interface, and result null? If yes -> return 0;
         *      if ( !interface || !*interface || (result = (*interface)[index]) == 0 ) result = 0;
         *
         *      //Return virtual function address.
         *      return result;
         *
         * }
         *
         */

        extern int __fastcall CallVirtualFunction (int* vTable, int index);

    };

};