#include "OneSegment.hpp"

Segment::SegmentData OneSegment::GetSegmentData () {
    return SegmentData { 0x186A00, 0x4738C };
}

AdditionalRuntime::AllocaParameters OneSegment::GetAllocationParameters () {
    return AdditionalRuntime::AllocaParameters { 0x0, 0x968940, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE };
}

Segment::ReconstructProcessorDefinition OneSegment::GetReconstructProcessorDefinition () {
    return ReconstructProcessorDefinition { &m_relocationInfo, &m_importInfo };
}