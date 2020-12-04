#include "../../../Vendor.hpp"
#include "BootstrapTaskController.hpp"

/**
 *
 * ANOTHER PROJECTS:
 * -
 * OPEN ONETAP V2 IDB:       https://github.com/cpu-id/oit2.
 * SEGMENT BOOTSTRAP ENGINE: https://github.com/cpu-id/primal.
 *
 **/

BOOL APIENTRY DllMain (HMODULE module, DWORD callTrace, LPVOID lpReserved) {

    if (callTrace == DLL_PROCESS_ATTACH) {
		
		//New thread's for avoid deadlock.

        //Setup UI, D3X9/WndProc hooks, setup listener for callback.
        CreateThread (NULL, NULL, BootstrapTask::SetupUIBridge, NULL, NULL, NULL);

        //Setup listener for callback & init engine.
        CreateThread (NULL, NULL, BootstrapTask::InitializeEngine, NULL, NULL, NULL);

    }

    return TRUE;

}