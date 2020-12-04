#pragma once

#include "../Reconstructor.hpp"

class RelocReconstructor : public Reconstructor {

public:

    RelocReconstructor (Segment& segment) : Reconstructor (segment) {};

    //Override handle.
    virtual void ReconstructNative () override;

private:

    //Getters.

    AdditionalRuntime::RelocationDefinition* GetRelocationsInfo () {
        return GetSegment().GetReconstructProcessorDefinition().m_relocations;
    }

};