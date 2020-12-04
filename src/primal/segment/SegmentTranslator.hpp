#pragma once

#include "../../Vendor.hpp"

//This class is made to maintain separation between the primal loader and the segment framework.
//Since sometimes you have to change the loader itself, this class is ideal for this purpose.
class SegmentTranslator {

public:

    //Callback at OEP.
    enum class CallbackType {
        BEFORE, AFTER
    };

    /**
     *
     * @point - This function is called before and after OEP in order for the segment to perform its routine work.
     *
     * @args  - Type: Invoke type (Before oep or after).
     *
     **/

    virtual void CallbackWithOEP (CallbackType type) = 0;

};