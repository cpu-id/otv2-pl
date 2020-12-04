#pragma once

#include "sections/SectionAccessor.hpp"
#include "../../primal/segment/internal/SegmentProvider.hpp"

class OneSegment : public Segment {

public:

    virtual Segment::SegmentData GetSegmentData () override;

    virtual AdditionalRuntime::AllocaParameters GetAllocationParameters () override;

    virtual Segment::ReconstructProcessorDefinition GetReconstructProcessorDefinition () override;

private:

    AdditionalRuntime::RelocationDefinition m_relocationInfo = { 0x3D600000, SectionAccessor::Relocations, 22980 };
    std::map <std::string, std::vector <AdditionalRuntime::ImportDefinition>> m_importInfo = SectionAccessor::IAT;

};