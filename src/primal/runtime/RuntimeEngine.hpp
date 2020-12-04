#pragma once

#include "../../Vendor.hpp"
#include "../segment/internal/SegmentProvider.hpp"
#include "reconstructor/Reconstructor.hpp"
#include "reconstructor/reconstructors/IATReconstructor.hpp"
#include "reconstructor/reconstructors/RelocReconstructor.hpp"

class RuntimeEngine {

public:

    RuntimeEngine (Segment& segment) : m_segment (segment) {

        //Setup alloc data.
        Primal::AllocParameters = segment.GetAllocationParameters();

        //Verify segment data.
        if ((segment.GetSegmentData().m_oep == 0 || segment.GetSegmentData().m_oep > segment.GetSegmentData().m_size) || segment.GetSegmentData().m_size == 0) {
            Primal::PanicUtil::Release ("RuntimeEngine@Constructor->VerifySegmentData.", "Invalid segment parameters. Please re-setup segment data.");
        }

        //Verify alloc data.
        if ((Primal::AllocParameters.m_size == 0 || Primal::AllocParameters.m_size < segment.GetSegmentData().m_size) || Primal::AllocParameters.m_type == 0 || Primal::AllocParameters.m_protect == 0) {
            Primal::PanicUtil::Release ("RuntimeEngine@Constructor->VerifyAllocaData.", "Invalid allocation parameters. Please re-setup segment allocation settings.");
        }

    };

    /**
     *
     * @function - ExtractSegment.
     * @point    - Allocate memory for segment & copy segment into new region.
     *
     * @function - ExecuteReconstruction.
     * @point    - Invoke IATReconstructor and RelocReconstructor.
     *
     * @function - Invoke OEP.
     * @point    - Just invoke original entry point. (Template in RuntimeDefinitions)
     *
     */

    void ExtractSegment (), ExecuteReconstruction (), InvokeOEP ();

    //Getters.

    Segment::SegmentData GetSegmentData () {
        return m_segment.GetSegmentData();
    }

    Segment::ReconstructProcessorDefinition GetReconstructProcessorDefinition () {
        return m_segment.GetReconstructProcessorDefinition();
    }

    IATReconstructor GetIatReconstructor () {
        return m_iatReconstructor;
    }

    RelocReconstructor GetRelocReconstructor () {
        return m_relocReconstructor;
    }

private:

    //Segment for data.
    Segment& m_segment;

    //Reconstructors.
    IATReconstructor m_iatReconstructor = IATReconstructor (m_segment);
    RelocReconstructor m_relocReconstructor = RelocReconstructor (m_segment);

};