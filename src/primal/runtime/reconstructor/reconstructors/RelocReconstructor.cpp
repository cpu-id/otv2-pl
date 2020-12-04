#include "RelocReconstructor.hpp"

void RelocReconstructor::ReconstructNative () {

    //Iterate relocations in memory. (4 bytes as unpacked)
    do {

        //Subtract value with old base address in segment from memory.
        *reinterpret_cast <int*> (GetAllocationParameters().m_base + *GetRelocationsInfo()->m_relocations) -= GetRelocationsInfo()->m_oldAllocationBase;
        //Add new base address in segment to relocations.
        *reinterpret_cast <int*> (GetAllocationParameters().m_base + *GetRelocationsInfo()->m_relocations) += GetAllocationParameters().m_base;

        //Change current relocation to next.
        GetRelocationsInfo()->m_relocations++;
        GetRelocationsInfo()->m_relocationCount--;

    } while (GetRelocationsInfo()->m_relocationCount != 0);

}