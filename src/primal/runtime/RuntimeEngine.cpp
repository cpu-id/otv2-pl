#include "RuntimeEngine.hpp"

void RuntimeEngine::ExtractSegment () {

    //Allocate memory for segment & verify it.
    int segmentAllocation = reinterpret_cast <int> (VirtualAlloc (reinterpret_cast <void*> (Primal::AllocParameters.m_base), Primal::AllocParameters.m_size, Primal::AllocParameters.m_type, Primal::AllocParameters.m_protect));

    if (segmentAllocation == 0) {
        Primal::PanicUtil::Release ("RuntimeEngine@ExtractSegment->VirtualAlloc", "Can't allocate virtual memory.");
    }

    //Copy segment into new memory & verify it.
    if (!memcpy (reinterpret_cast <void*> (segmentAllocation), SegmentNativeData, GetSegmentData ().m_size)) {
        Primal::PanicUtil::Release ("RuntimeEngine@ExtractSegment->memcpy", "Can't copy segment to allocation memory.");
    }

    //Set new global allocation base.
    Primal::AllocParameters.m_base = segmentAllocation;

}

void RuntimeEngine::ExecuteReconstruction () {

    //Reconstructors verify routine...
    if (!GetReconstructProcessorDefinition().m_iat->empty()) { GetIatReconstructor().ReconstructNative(); }
    if (GetReconstructProcessorDefinition().m_relocations->m_relocations != 0x00000000) { GetRelocReconstructor().ReconstructNative(); }

}

void RuntimeEngine::InvokeOEP () {

    //Set function address for call.
    AdditionalRuntime::DllMain EntryPoint = reinterpret_cast <AdditionalRuntime::DllMain> (Primal::AllocParameters.m_base + GetSegmentData().m_oep);

    //Call "OEP" func with arguments.
    EntryPoint (reinterpret_cast <HMODULE> (Primal::AllocParameters.m_base), DLL_PROCESS_ATTACH, NULL);

}