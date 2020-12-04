#pragma once

#include "../../../Vendor.hpp"

namespace Callback {

    //Callback listener.
    extern HANDLE BackCallEvent;

    //Callback type classification.
    //
    // _WAIT    -> Waiting for callback exec.
    // _IN      -> Callback running.
    // _PRE_OUT -> Callback executed, wait for leave from callback zone.
    // _OUT     -> Complete.
    enum CallType { _WAIT, _IN, _PRE_OUT, _OUT };

    //Callback current status. [_WAIT, _IN, _OUT]
    extern CallType Status;

    //Used to rebuild the current UI render during the execution of the callback.
    extern bool IsRunning ();

    //Setters/Getters.

    extern CallType GetCurrentStatus ();

    extern void SetCurrentStatus (CallType type);

};