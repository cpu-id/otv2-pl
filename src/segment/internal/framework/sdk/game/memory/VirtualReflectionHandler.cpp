#include "VirtualReflectionHandler.hpp"

INT OneSDK::MemoryController::HookData::CallVirtualFunction__OffsetToHook = 0x3B30;

//Naked for remove prologue & epilogue.
__declspec (naked) int __fastcall OneSDK::MemoryController::CallVirtualFunction (int* vTable, int index) {

    __asm {

        ;
        ; @ecx - Virtual table pointer.
        ; @edx - Index.
        ; @eax - Output result. (Virtual function address)
        ;

        cmp edx, 152    ; cmp index to 152.
        jl getToVirtual ; jump if less.
        add edx, 2      ; index += 2.
        cmp edx, 256    ; cmp index to 256.
        jl getToVirtual ; jump if less.
        inc edx         ; index++.
        cmp edx, 300    ; cmp index to 300.
        jl getToVirtual ; jump if less.
        add edx, 2      ; index += 2.
        cmp edx, 300    ; cmp index to 300.
        jl getToVirtual ; jump if less.
        inc edx         ; index++.

        getToVirtual:                ; Get pointer to virtual function.

            mov eax, [ecx]           ; Get virtual table from instance.
            mov eax, [eax + edx * 4] ; Move virtual function address to eax.
            ret                      ; Exit.

    }

}