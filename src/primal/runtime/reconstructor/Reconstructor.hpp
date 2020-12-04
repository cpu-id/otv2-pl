#pragma once

#include "../../../Vendor.hpp"
#include "../../segment/internal/SegmentProvider.hpp"

//Provide new reconstructors by this abstract class.
class Reconstructor {

public:

    Reconstructor (Segment& segment) : m_segment (segment) {};

    /**
     *
     * @point - Reconstruct action at call in engine.
     *
     */

    virtual void ReconstructNative () = 0;

protected:

    //Getters.

    AdditionalRuntime::AllocaParameters GetAllocationParameters () {
        return Primal::AllocParameters;
    }

    Segment& GetSegment () {
        return m_segment;
    }

private:

    Segment& m_segment;

};