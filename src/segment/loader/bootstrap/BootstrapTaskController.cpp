#include "BootstrapTaskController.hpp"

DWORD WINAPI BootstrapTask::SetupUIBridge (_In_ LPVOID lpParameter) {

    //Create listener instance...
    UIBridge bridge = Singleton <UIBridge> :: GetInstance ();

    //Setup hooks/data/etc.
    bridge.Setup ();

    return 0;

}

DWORD WINAPI BootstrapTask::InitializeEngine (_In_ LPVOID lpParameter) {

    //Setup listener to event.
    WaitForSingleObject (Callback::BackCallEvent, INFINITE);

    //Setup primal engine.

      ///////////////////////////////////////////////////////////////////////////////////////
    //                                                                                      //
    // SEGMENT.                                                                             //
    //                                                                                      //
       OneSegment segment = Singleton <OneSegment> :: GetInstance ();                       //
       SegmentInterpreter framework = Singleton <SegmentInterpreter> :: GetInstance ();     //
    //                                                                                      //
     ////////////////////////////////////////////////////////////////////////////////////////
    //                                                                                      //
    //  RUNTIME.                                                                            //
    //                                                                                      //
        RuntimeEngine runtime (segment);                                                    //
    //                                                                                      //
     ////////////////////////////////////////////////////////////////////////////////////////

    //Hello msg.
    UI::DataWrapper::Load::PutMessageToLdOutput ("[->]", "primal.hello");

    //Prepare [1].
    UI::DataWrapper::Load::PutMessageToLdOutput ("[~]", "primal.prep.one");

    //Alloc memory && init variable.
    runtime.ExtractSegment ();

    //Passed [1].
    UI::DataWrapper::Load::PutMessageToLdOutput ("[V]", "primal.passed.one");

    //Prepare [2].
    UI::DataWrapper::Load::PutMessageToLdOutput ("[~]", "primal.prep.sec");

    //Reconstruct IAT and relocations table.
    runtime.ExecuteReconstruction ();

    //Passed [2].
    UI::DataWrapper::Load::PutMessageToLdOutput ("[V]", "primal.passed.sec");

    //Prepare [3].
    UI::DataWrapper::Load::PutMessageToLdOutput ("[~]", "primal.prep.seg.bef");

    //Segment routine.
    framework.CallbackWithOEP (SegmentTranslator::CallbackType::BEFORE);

    //Passed [3].
    UI::DataWrapper::Load::PutMessageToLdOutput ("[V]", "primal.passed.seg.bef");

    //Prepare [4].
    UI::DataWrapper::Load::PutMessageToLdOutput ("[~]", "primal.prep.thr");

    //Invoke original entry point or "Make segment alive".
    runtime.InvokeOEP ();

    //Passed [4].
    UI::DataWrapper::Load::PutMessageToLdOutput ("[V]", "primal.passed.thr");

    //Segment routine. [2]
    framework.CallbackWithOEP (SegmentTranslator::CallbackType::AFTER);

    //Is addons queue exist?
    if (!UI::DataWrapper::Load::GetFilePathToAddon (UI::DataWrapper::Load::OEPType::BEFORE).empty () || !UI::DataWrapper::Load::GetFilePathToAddon (UI::DataWrapper::Load::OEPType::AFTER).empty ()) {

        //Prepare [5].
        UI::DataWrapper::Load::PutMessageToLdOutput ("[~]", "primal.prep.seg.aft");

        //Passed [5].
        UI::DataWrapper::Load::PutMessageToLdOutput ("[V]", "primal.passed.seg.aft");

    }

    UI::DataWrapper::Load::PutMessageToLdOutput ("[<->]", "primal.finish");

    //Set global callback status to "ready2finish".
    Callback::SetCurrentStatus (Callback::CallType::_PRE_OUT);

    return 0;

}