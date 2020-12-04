#include "OneEngine.hpp"

void OneEngine::SetupHooks () {

    //Hook function for call vfuncs from SDK. [Allows you to update the cheat for the current version of the game]
    DetourFunction (reinterpret_cast <PBYTE> (Primal::AllocParameters.m_base + OneSDK::MemoryController::HookData::CallVirtualFunction__OffsetToHook), reinterpret_cast <PBYTE> (OneSDK::MemoryController::CallVirtualFunction));

}

void OneEngine::SetupInfoTable () {

    std::vector <DWORD> info;

    //Some offset to unknown place.
    //TODO: Need2Find Info.
    info.emplace_back (reinterpret_cast <DWORD> (CommonUtil::GetModule ("steamclient.dll") + 0x2A6900));

    //Base addresses of game modules for routine operations in the onetap.
    for (const auto& library : m_libraries) info.emplace_back (reinterpret_cast <DWORD> (CommonUtil::GetModule (library)));

    //We scan signatures in real time, and move what we got (offsets) to the table.
    //Offsets are needed so that OneTap internal functions can find functions from outside.
    for (const auto& signature : m_interfaces) {
        info.emplace_back (CommonUtil::SearchSignature ("client", signature));
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // And so, consider everything in order. Here we move the finished table to the allocated segment memory.                                                    //
    // Onetap has a function that automatically takes information from the allocated memory because it knows what will be there: "Libraries, Offsets."           //
    // Since the original loader loads there as we do.                                                                                                           //
    //                                                                                                                                                           //
    // What is the number 0x20 and why is it here? The function starts reading data (base addresses, offsets) starting from: Base address + offset by 0x20 bytes //
    // And since we only have data that the function reads in the table, we can safely move the data directly to the place where the function reads.             //
    //                                                                                                                                                           //
        std::memmove (reinterpret_cast <PVOID> (Primal::AllocParameters.m_base + 0x20), reinterpret_cast <PVOID> (info.data ()), 0x18C);                         //
    //                                                                                                                                                           //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


}

void OneEngine::InstallMicroPatches () {

    //Fix netvars values for current update.
    for (const auto& netvar : m_netvars) {
        *reinterpret_cast <int*> (Primal::AllocParameters.m_base + netvar.m_rva) = netvar.m_value;
    }

}

void OneEngine::InstallLoaderModification () {

    /**
     *
     * @point - Update instruction argument with char array.
     *
     * @arg0 compressedArray          - Char array with limited length.
     * @arg1 offsetToInstructions     - Instruct offset. (Base address + offsetToInstruct = InstructionArgumentStartPos)
     * @arg2 instructionIteratorBase  - Iterator offset base. (Base address + offsetToInstruct + instructionIterator = Next instruction)
     * @arg3 instructionCount         - Next instruction count. (InstructionSize * Count = InstructionCount)
     * @arg4 iterationCycleUpdate     - Iterator sum update. (Iteration += InstructionSize)
     * @arg5 instructionCharMoveCount - Count symbols move from array to instruction argument. (Example: For mov instruction need 0x4 bytes)
     * @arg6 arrayCharIteratorBase    - Start array pos.
     * @arg7 arrayCharCycleUpdate     - Iterator sum update.
     *
     **/

    auto UpdateLegacyInstructionString = [](char compressedArray[], int offsetToInstructions, int instructionIteratorBase, int instructionCount, int iterationCycleUpdate, int instructionCharMoveCount, int arrayCharIteratorBase, int arrayCharCycleUpdate) {

        int segmentedCharIterator = arrayCharIteratorBase;

        for (int instructionsIterator = instructionIteratorBase; instructionsIterator < instructionCount; instructionsIterator += iterationCycleUpdate) {
            std::memcpy (reinterpret_cast <int*> (Primal::AllocParameters.m_base + offsetToInstructions + instructionsIterator), compressedArray + segmentedCharIterator, instructionCharMoveCount);
            segmentedCharIterator += arrayCharCycleUpdate;
        }

    };

    //Start setup watermark [box].
    char userName [16];
    //Copy size.
    DWORD sizeOfUserName = 16;
    //Copy user name to compressed watermark array.
    GetUserNameA (userName, &sizeOfUserName);
    //Update string inside function mov instruction.
    UpdateLegacyInstructionString (userName, 0x12D381, 0x0, 0x1C, 0x7, 0x4, 0x0, 0x4);
    //We move the username to the start of the segment since the function reads the username first, then the libraries, then the offsets.
    std::memmove (reinterpret_cast <int*> (Primal::AllocParameters.m_base + 0x1), userName, 0x20);

    //-------------

    //Start setup watermark [menu].
    //Update string inside function mov instruction.
    UpdateLegacyInstructionString ("OneTap", 0xE025F, 0x0, 0x15, 0x7, 0x4, 0x0, 0x4);


}