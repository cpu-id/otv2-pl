#include "PanicUtil.hpp"

void Primal::PanicUtil::Release (const char* caller, const char* reason) {

    /**
     *
     * @point - Format panic message.
     *
     * @args  - Caller: Call-in function (Style: Class@Function->Stage). Reason: Panic release reason.
     *
     */

    auto GenerateMessage = [](const char* caller, const char* reason) { return (std::stringstream () << "\n" << "_--------- PL_PANIC --------_\n" << "|\n" << "| Caller: " << caller << ".\n" << "| Reason: " << reason << ".\n" << "|\n" << "_--------- PL_PANIC --------_").str (); };

    //TODO: Multi-output support?
    if (IsDebuggerPresent ()) {

        OutputDebugStringA (GenerateMessage (caller, reason).c_str ());
        DebugBreak ();

    } else {

        ExitProcess (0xDEAD);

    }


}