#include "CallbackManager.hpp"

//TODO: Instant load mode.
Callback::CallType Callback::Status = Callback::CallType::_WAIT;
HANDLE Callback::BackCallEvent = CreateEvent (nullptr, TRUE, FALSE, nullptr);

bool Callback::IsRunning () {
    return Callback::Status == Callback::CallType::_IN || Callback::Status == Callback::CallType::_PRE_OUT;
}

Callback::CallType Callback::GetCurrentStatus () {
    return Callback::Status;
}

void Callback::SetCurrentStatus (Callback::CallType type) {
    Callback::Status = type;
}