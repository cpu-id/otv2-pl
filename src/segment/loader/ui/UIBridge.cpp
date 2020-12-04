#include "UIBridge.hpp"

void UIBridge::Setup () {

    //Search HWND.
    while (EnumWindows (UIBridge::EnumWindowsProc, 0));

    //Re-set wndproc handle to our wndproc function for handle callback action.
    UIBridge::OriginalWndProc = reinterpret_cast <WNDPROC> (SetWindowLongW (UIBridge::CurrentHWND, GWL_WNDPROC, reinterpret_cast <LONG_PTR> (&UIBridge::WndProc)));

    //Get pointer to end scene function, from d3x9 device virtual table.
    auto d3xDevice = **reinterpret_cast <IDirect3DDevice9***> (CommonUtil::SearchSignature ("shaderapidx9.dll", "A1 ? ? ? ? 50 8B 08 FF 51 0C") + 1);
    void** d3xDeviceVirtualTable = *reinterpret_cast <void***> (d3xDevice);

    //Hook end scene for show our ui.
    UIBridge::OriginalEndScene = reinterpret_cast <UIBridge::EndSceneTemplate> (DetourFunction (reinterpret_cast <PBYTE> (d3xDeviceVirtualTable [42]), reinterpret_cast <PBYTE> (UIBridge::EndScene)));

}

//COMMON SHARED HOOKS.

//Win32 message handler.
LRESULT WINAPI UIBridge::WndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    /**
     *
     * @point - Set default application wnd controller to custom imgui controller.
     * @args  - WndProc pack.
     *
     * @author - 0x000cb. / 17.10.20
     *
     */

    auto ProcessImGuiWndController = [](HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

        switch (msg) {

            case WM_KEYDOWN: {

                //Check for load state.
                if (GetAsyncKeyState (VK_RETURN) & 0x8000 &&
                    UI::DataWrapper::Frames::CmpCurrentPage (UI::DataWrapper::Frames::Pages::LOAD) &&
                    UI::DataWrapper::Frames::CmpCurrentLoadPage (UI::DataWrapper::Frames::LoadPages::SEGMENT)) {

                    if (Callback::Status != Callback::CallType::_OUT) {

                        //It's first load?
                        if (Callback::Status != Callback::CallType::_PRE_OUT) {

                            //Change global callback status to "execute". (And send notify to menu handler)
                            Callback::SetCurrentStatus (Callback::CallType::_IN);

                            //Set rpc load status to init.
                            DiscordRPC::SetRpcState (UI::DataWrapper::Language::TranslateMessage ("sett.us.disrpc.gm"));

                            //Signal to engine for startup.
                            SetEvent (Callback::BackCallEvent);

                        //Load done?
                        } else {

                            //Change global callback status to "executed". (And send notify to menu handler)
                            Callback::SetCurrentStatus (Callback::CallType::_OUT);

                            //Set rpc load status to done.
                            DiscordRPC::SetRpcState (UI::DataWrapper::Language::TranslateMessage ("sett.us.disrpc.gm"));

                            //Flush temp buffers. [Load log, addons list]
                            UI::Storage::FlushCandidateTempBuffers ();

                        }

                    }

                }

                ImGui::GetIO ().KeysDown [wParam] = 1;
                return 1;

            }

            //Common imgui wndproc handler.
            case WM_LBUTTONDOWN: case WM_LBUTTONDBLCLK:
            case WM_RBUTTONDOWN: case WM_RBUTTONDBLCLK:
            case WM_MBUTTONDOWN: case WM_MBUTTONDBLCLK:
            {
                int button;
                if (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONDBLCLK) button = 0;
                if (msg == WM_RBUTTONDOWN || msg == WM_RBUTTONDBLCLK) button = 1;
                if (msg == WM_MBUTTONDOWN || msg == WM_MBUTTONDBLCLK) button = 2;
                if (!ImGui::IsAnyMouseDown () && ::GetCapture () == NULL) ::SetCapture (hwnd);
                ImGui::GetIO ().MouseDown [button] = true;
                return 1;
            }
            case WM_LBUTTONUP:
            case WM_RBUTTONUP:
            case WM_MBUTTONUP:
            {
                int button;
                if (msg == WM_LBUTTONUP) button = 0;
                if (msg == WM_RBUTTONUP) button = 1;
                if (msg == WM_MBUTTONUP) button = 2;
                ImGui::GetIO ().MouseDown [button] = false;
                if (!ImGui::IsAnyMouseDown( ) && ::GetCapture () == hwnd) ::ReleaseCapture ();
                return 1;
            }
            case WM_MOUSEWHEEL:
                ImGui::GetIO ().MouseWheel += GET_WHEEL_DELTA_WPARAM(wParam) > 0 ? +1.0f : -1.0f;
                return 1;
            case WM_MOUSEHWHEEL:
                ImGui::GetIO ().MouseWheelH += GET_WHEEL_DELTA_WPARAM(wParam) > 0 ? +1.0f : -1.0f;
                return 1;
            case WM_MOUSEMOVE:
                ImGui::GetIO ().MousePos.x = static_cast <signed short> (lParam);
                ImGui::GetIO ().MousePos.y = static_cast <signed short> (lParam >> 16);
                return 1;
            case WM_SYSKEYDOWN:
                if (wParam < 256)
                    ImGui::GetIO( ).KeysDown [wParam] = 1;
                return 1;
            case WM_KEYUP:
            case WM_SYSKEYUP:
                if (wParam < 256)
                    ImGui::GetIO ().KeysDown [wParam] = 0;
                return 1;
            case WM_CHAR:
                if (wParam > 0 && wParam < 0x10000)
                    ImGui::GetIO ().AddInputCharacter(static_cast <unsigned short> (wParam));
                return 1;

        }

    };


    //Del handler.
    if (msg == WM_KEYDOWN && GetAsyncKeyState (VK_DELETE) & 0x8000 && !Callback::IsRunning ()) {
        UI::Fundamental::IsMenuShowing = !UI::Fundamental::IsMenuShowing;
        return 1;
    }

    //Insert handler.
    if (msg == WM_KEYDOWN && GetAsyncKeyState (VK_INSERT) & 0x8000 && Callback::Status == Callback::CallType::_OUT && UI::Fundamental::IsMenuShowing) {
        UI::Fundamental::IsMenuShowing = false;
        return 1;
    }

    if (UI::Fundamental::IsMenuShowing) {

        ProcessImGuiWndController (hwnd, msg, wParam, lParam);

        return 1;

    }

    return CallWindowProc (UIBridge::OriginalWndProc, hwnd, msg, wParam, lParam);
}

HRESULT CALLBACK UIBridge::EndScene (IDirect3DDevice9* device) {

    //Handle buffer overflow.
    static auto stackReturnAddress = _ReturnAddress ();

    if (_ReturnAddress () == stackReturnAddress && UI::Fundamental::IsMenuShowing) {

        if (!UIBridge::IsUiInitialized) {

            //Prepare render devices.
            UI::Fundamental::D3X::Device = device;
            UI::Fundamental::Wakeup (UIBridge::CurrentHWND);

            UIBridge::IsUiInitialized = true;

        }

       	DWORD colorWrite, srgbWrite;

        device->GetRenderState (D3DRS_COLORWRITEENABLE, &colorWrite);
	    device->GetRenderState (D3DRS_SRGBWRITEENABLE, &srgbWrite);
    	device->SetRenderState (D3DRS_SRGBWRITEENABLE, false);

        //Prepare frame.
        ImGui_ImplDX9_NewFrame ();
	    ImGui_ImplWin32_NewFrame ();
	    ImGui::NewFrame ();

        //Fill the frame.
        UI::Fundamental::RenderFrameBuffer ();

        //Render the frame.
        ImGui::EndFrame ();
        ImGui::Render ();

        ImGui_ImplDX9_RenderDrawData (ImGui::GetDrawData ());

        device->SetRenderState (D3DRS_COLORWRITEENABLE, colorWrite);
        device->SetRenderState (D3DRS_SRGBWRITEENABLE, srgbWrite);


    }

    return UIBridge::OriginalEndScene (device);

}

BOOL CALLBACK UIBridge::EnumWindowsProc (HWND hwnd, LPARAM param) {

    DWORD winThreadId;
    GetWindowThreadProcessId (hwnd, &winThreadId);

    if (winThreadId == GetCurrentProcessId ()) {
        UIBridge::CurrentHWND = hwnd;
        return FALSE;
    }

    return TRUE;

}

//Default externs.
HWND UIBridge::CurrentHWND = NULL;
bool UIBridge::IsUiInitialized = false;
UIBridge::EndSceneTemplate UIBridge::OriginalEndScene = nullptr;
WNDPROC UIBridge::OriginalWndProc = nullptr;