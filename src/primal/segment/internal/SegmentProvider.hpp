#pragma once

#include "../../../Vendor.hpp"

//Segment as C-array view.
extern const unsigned char SegmentNativeData [];

//Provider for real segment.
class Segment {

public:

    struct SegmentData {

        //Size of segment data.
        int m_size;
        //Offset to original entry point.
        int m_oep;

    };

    struct ReconstructProcessorDefinition {

        // ____________________________________
        //
        // RELOCATIONS.
        //
        // Setup view:
        //
        //   Settings present?
        //                     Yes -> Parse relocation type -> Process relocation -> Set new value.
        //                     No  -> Do instant set new value.
        //
            AdditionalRuntime::RelocationDefinition* m_relocations;
        //
        // ------------------------------------
        //
        // IAT.
        //
        // Setup view:
        //
        //   Library name ->
        //                   Function name
        //                                 ->
        //                                    List of RVA
        //
            std::map <std::string, std::vector <AdditionalRuntime::ImportDefinition>>* m_iat;
        //
        // ____________________________________

    };

    /**
     *
     * @point - Get segment size & oep to offset.
     *
     */

    virtual SegmentData GetSegmentData () = 0;

    /**
     *
     * @point - Get allocation size. (& Additional stuff like base, type, protect)
     *
     */

    virtual AdditionalRuntime::AllocaParameters GetAllocationParameters () = 0;

    /**
     *
     * @point - Get pointer to relocations and iat data.
     *
     */

    virtual ReconstructProcessorDefinition GetReconstructProcessorDefinition () = 0;

};