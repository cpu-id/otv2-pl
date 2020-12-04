#pragma once

#include "../../Vendor.hpp"
#include "framework/OneEngine.hpp"
#include "../loader/ui/UIRenderer.hpp"
#include "../../primal/segment/SegmentTranslator.hpp"

//SegmentInterpreter -> Segment init routine [before/after oep].
class SegmentInterpreter : public SegmentTranslator {

public:

	void CallbackWithOEP (CallbackType type) override {

        switch (type) {

            case CallbackType::BEFORE: {

                //VFC.
                engine.SetupHooks ();
                //Third-side dependency.
                engine.SetupInfoTable ();
                //Updates, etc.
                engine.InstallMicroPatches ();
                //Dependency at UI.
                engine.InstallLoaderModification ();

                //Load third-party addons. [Before OEP]
                for (const auto& addon : UI::DataWrapper::Load::GetFilePathToAddon (UI::DataWrapper::Load::OEPType::BEFORE)) {

                    //Bypass csgo LL security.........
                    *reinterpret_cast <int*> (CommonUtil::SearchSignature ("csgo.exe", "1B F6 45 0C 20")) = 0x74;

                    LoadLibraryA (addon.c_str ());

                }

            }; break;

            case CallbackType::AFTER: {

                //Load third-party addons. [After OEP]
                for (const auto& addon : UI::DataWrapper::Load::GetFilePathToAddon (UI::DataWrapper::Load::OEPType::AFTER)) {

                    LoadLibraryA (addon.c_str ());

                }

                //Hide the menu.
                *reinterpret_cast <int*> (Primal::AllocParameters.m_base + 0x485F67) = false;

            }; break;

        }

	};

private:

    OneEngine engine = Singleton <OneEngine> :: GetInstance ();

};