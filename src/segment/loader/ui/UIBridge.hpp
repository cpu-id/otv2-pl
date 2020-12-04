#pragma once

#include "UIRenderer.hpp"
#include "../../../Vendor.hpp"
#include "../callback/CallbackManager.hpp"

class UIBridge {

public:

    //Template for call.
    typedef HRESULT (__stdcall* EndSceneTemplate) (IDirect3DDevice9* device);

    /**
     *
     * @point - Setup hooks for render ui & advice.
     *
     * @author - 0x000cb. / 10.10.20
     *
     */

    void Setup ();

    //Docs: https://docs.microsoft.com/en-us/windows/win32/api/d3d9/nf-d3d9-idirect3ddevice9-endscene.
    static HRESULT CALLBACK EndScene (IDirect3DDevice9* device);
    //Docs: https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms633573(v=vs.85) (P.S: Most used for WM_KEYPRESS hook)
    static LRESULT WINAPI WndProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    //Search current process hwnd.
    static BOOL CALLBACK EnumWindowsProc (HWND hwnd, LPARAM param);

private:

    //Internal.

    //Application HWND.
    static HWND CurrentHWND;
    //Is UI ready to work?
    static bool IsUiInitialized;

    //Hooks.

    //Original wndproc handler address.
    static WNDPROC OriginalWndProc;
    //Original endscene handler address.
    static EndSceneTemplate OriginalEndScene;

};