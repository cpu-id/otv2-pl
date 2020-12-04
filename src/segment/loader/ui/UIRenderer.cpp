#include "UIRenderer.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                     //
//                  +---------------------+                                                           //
//                  |    Common fonts.    |                                                          //
//                  +---------------------+                                                         //
//                                                                                                 //
   #include "../../../../thirdparty/source/gui/fonts/nunito/NunitoExtraBold.hpp"                  //
   #include "../../../../thirdparty/source/gui/fonts/nunito/NunitoSemiBold.hpp"                  //
   #include "../../../../thirdparty/source/gui/fonts/nunito/NunitoBold.hpp"                     //
   #include "../../../../thirdparty/source/gui/fonts/nunito/NunitoLight.hpp"                   //
   #include "../../../../thirdparty/source/gui/fonts/icons/OTCIcons.hpp"                      //
   #include "../../../../thirdparty/source/gui/fonts/sourcecodepro/SourceCodeProLight.hpp"   //
// ________________________________________________________________________________________ //
//                                                                                         //
//            +---------------------+                                                     //
//            | Logo for d3x9 draw. |                                                    //
//            +---------------------+                                                   //
//                                                                                     //
   #include "../../../../thirdparty/source/gui/images/Logo.hpp"                       //
// _________________________________________________________________________________ //
//////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Externs for: interfaces, enums, bools, maps, vectors, etc...
// ____________________________________________________________
//
    int UI::Fundamental::VersionControl::BuildMajorVer = 1;
    int UI::Fundamental::VersionControl::BuildLocalVer = 0;
//
// --------------------------------------------------------->
//
    PDIRECT3DDEVICE9 UI::Fundamental::D3X::Device = NULL;
    LPDIRECT3DTEXTURE9 UI::Fundamental::D3X::LogoTexture = nullptr;
//
// --------------------------------------------------------->
//
    bool UI::Fundamental::IsMenuShowing = true;
//
// --------------------------------------------------------->
//
    ImFont* UI::Fundamental::Fonts::NunitoLight = nullptr;
    ImFont* UI::Fundamental::Fonts::NunitoBold = nullptr;
    ImFont* UI::Fundamental::Fonts::NunitoSemiBold = nullptr;
    ImFont* UI::Fundamental::Fonts::NunitoExtraBold = nullptr;
    ImFont* UI::Fundamental::Fonts::SourceCodeProLight = nullptr;
    ImFont* UI::Fundamental::Fonts::SysIcons = nullptr;
//
// --------------------------------------------------------->
//
    LanguageProvider::Region UI::Storage::SystemBuffers::SelectedRegion = LanguageProvider::Region::EN;
//
// --------------------------------------------------------->
//

    std::map <std::string, int> UI::Storage::SystemBuffers::Frames::Pages = {

        { "menu.page",         UI::DataWrapper::Frames::Pages::NEWS       },
        { "load.page",         UI::DataWrapper::Frames::LoadPages::README },
        { "load.seg.out.type", UI::Fundamental::Buffers::TEMP_LOAD_INFO   }

    };

    std::map <LanguageProvider::Region, std::vector <UI::DataWrapper::News::DayNews>> UI::Storage::TextBuffers::NewsData = {

        { LanguageProvider::Region::EN, {

            UI::DataWrapper::News::DayNews { u8"Engine global update!", u8"03:50PM | 30 / 10/ 20",

                std::map <UI::DataWrapper::News::Type, std::map <UI::DataWrapper::News::Category, std::vector <const char*>>> {

                { UI::DataWrapper::News::Type::LOADER, {

                    { UI::DataWrapper::News::Category::ADDED,

                      {
                        u8"Own reconstructor support.",
                        u8"New relocation type support. [Standalone]",

                        }
                     },

                     { UI::DataWrapper::News::Category::IMPROVED,

                       {
                         u8"Signature scanner.",
                         u8"IAT reconstructor."
                       }

                     },

                     { UI::DataWrapper::News::Category::REWORKED,

                       {
                         u8"IAT/Reloc reconstructors.",
                         u8"Segment data processing.",
                         u8"Runtime engine."
                       }

                     }

                }

            } }, ImVec2 (321, 305) },

            UI::DataWrapper::News::DayNews { u8"OTv2 has new load engine !", u8"10:25AM | 17 / 10 / 20",

                std::map <UI::DataWrapper::News::Type, std::map <UI::DataWrapper::News::Category, std::vector <const char*>>> {

                    { UI::DataWrapper::News::Type::OTC, {

                      { UI::DataWrapper::News::Category::ADDED,

                         {
                            u8"Netvars.",
                            u8"ASM reconstruction of call virtual function hook.",
                         }

                      },

                      { UI::DataWrapper::News::Category::IMPROVED,

                         {
                            u8"Info-table signatures."
                         }

                      }
                    } },
                                                  
                    { UI::DataWrapper::News::Type::LOADER, { 
                      
                      { UI::DataWrapper::News::Category::ADDED,
        
                         {
                            u8"Primal-loader. (As the main engine)",
                            u8"Callback's.",
                            u8"Discord-RPC."
                         } 

                      } 

                    } 
                } 

            }, ImVec2 (321, 235) },

        } },

        { LanguageProvider::Region::RU, {

            UI::DataWrapper::News::DayNews { u8"Глобальное обновление движка !", u8"03:50 | 30 / 10/ 20",

              std::map <UI::DataWrapper::News::Type, std::map <UI::DataWrapper::News::Category, std::vector <const char*>>> {

                { UI::DataWrapper::News::Type::LOADER, {

                    { UI::DataWrapper::News::Category::ADDED,

                      {
                        u8"Поддержка собственных реконструкторов.",
                        u8"Новый тип релокаций. [Standalone]",
                      }

                    },

                    { UI::DataWrapper::News::Category::IMPROVED,

                      {
                        u8"Сканнер сигнатур.",
                        u8"IAT реконструктор."
                      }

                    },

                    { UI::DataWrapper::News::Category::REWORKED,

                      {
                        u8"IAT/Reloc реконструкторы.",
                        u8"Обработка данных сегмента.",
                        u8"Рантайм движок."
                      }

                    }

                } }
            }, ImVec2 (321, 305) },

            UI::DataWrapper::News::DayNews {  u8"У OTv2 появился новый движок ! ",  u8"10:25 | 17 / 10 / 20",

                std::map <UI::DataWrapper::News::Type, std::map <UI::DataWrapper::News::Category, std::vector <const char*>>> {

                    { UI::DataWrapper::News::Type::OTC, { 
                        
                      { UI::DataWrapper::News::Category::ADDED, 
            
                         { 
                            u8"Нетвары.",
                            u8"АСМ реконструкция вызова виртуальной функции.",
                         } 

                      },
                      { UI::DataWrapper::News::Category::IMPROVED, 

                         { 
                            u8"Info-table сигнатуры."
                         } 

                      } 
                    } }, 
            
                    { UI::DataWrapper::News::Type::LOADER, { 

                      { UI::DataWrapper::News::Category::ADDED,
                         
                         { 
                            u8"Primal-loader. (Как главный движок)",
                            u8"Обратные вызовы.",
                            u8"Discord-RPC."
                         } 
                        
                      } 
                    
                    }
                }
            }, ImVec2 (321, 235) }, }
        }
    };

//
// --------------------------------------------------------->
//
//  Empty buffers.

    std::map <std::string, bool> UI::Storage::SystemBuffers::Frames::LocalObjectsStatus = { };

    std::map <UI::DataWrapper::Load::OEPType, std::vector <std::string>> UI::Storage::TempBuffers::Load::Addons = { 
    
        { UI::DataWrapper::Load::OEPType::BEFORE, { } },
        { UI::DataWrapper::Load::OEPType::AFTER,  { } }
    
    };

Concurrency::concurrent_vector <UI::DataWrapper::PrefixedText> UI::Storage::TempBuffers::Load::Info;
Concurrency::concurrent_vector <UI::DataWrapper::PrefixedText> UI::Storage::TempBuffers::Load::Debug;

//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void UI::Fundamental::Wakeup (HWND hwnd) {

    //Low-level stuff.
    ImGui::CreateContext ();
    ImGuiIO& io = ImGui::GetIO ();

    //Set font by default.
    io.Fonts->AddFontFromMemoryTTF (NunitoBold, sizeof (NunitoBold), 16.f, nullptr, io.Fonts->GetGlyphRangesCyrillic ());

    //Set font for extension detail info. (Also it's just light font)
    UI::Fundamental::Fonts::NunitoLight = io.Fonts->AddFontFromMemoryTTF (NunitoLight, sizeof (NunitoLight), 18.f, nullptr, io.Fonts->GetGlyphRangesCyrillic ());

    //Set font for tabs. (Also it's just default font)
    UI::Fundamental::Fonts::NunitoBold = io.Fonts->AddFontFromMemoryTTF (NunitoBold, sizeof (NunitoBold), 18.f, nullptr, io.Fonts->GetGlyphRangesCyrillic ());

    //Set font for loader name in logo.
    UI::Fundamental::Fonts::NunitoExtraBold = io.Fonts->AddFontFromMemoryTTF(NunitoExtraBold, sizeof(NunitoExtraBold), 22.f, nullptr, io.Fonts->GetGlyphRangesCyrillic ());

    //Set font for build info.
    UI::Fundamental::Fonts::NunitoSemiBold = io.Fonts->AddFontFromMemoryTTF(NunitoSemiBold, sizeof(NunitoSemiBold), 16.f, nullptr, io.Fonts->GetGlyphRangesCyrillic ());

    //Set font for icons. (Used by default in tabs)
    UI::Fundamental::Fonts::SysIcons = io.Fonts->AddFontFromMemoryTTF (Icons, sizeof (Icons), 20.f);

    //Set font for output. (Console log, events, etc)
    UI::Fundamental::Fonts::SourceCodeProLight = io.Fonts->AddFontFromMemoryTTF (SourceCodeProLight, sizeof (SourceCodeProLight), 16.f, nullptr, io.Fonts->GetGlyphRangesCyrillic ());

    //Config stuff...
    io.ConfigFlags |= ImGuiConfigFlags_IsSRGB;
    //ImGui::StyleColorsDark ();
    ImVec4* colors = ImGui::GetStyle ().Colors;
    colors [ImGuiCol_ChildBg] = ImVec4 (0.13f, 0.13f, 0.13f, 0.17f), colors [ImGuiCol_Border] = ImVec4 (1.00f, 1.00f, 1.00f, 0.03f);

    //Init d3x.
    ImGui_ImplWin32_Init (hwnd);
    ImGui_ImplDX9_Init (UI::Fundamental::D3X::Device);

    //Small fixup for logo render.
    if (UI::Fundamental::D3X::LogoTexture == nullptr) {
        D3DXCreateTextureFromFileInMemoryEx (UI::Fundamental::D3X::Device, &Logo, sizeof (Logo), 49, 55, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, NULL, reinterpret_cast <D3DXIMAGE_INFO*> (NULL), reinterpret_cast <PALETTEENTRY*> (NULL), &UI::Fundamental::D3X::LogoTexture);
    }

    //Routine checks: Version control (Need to reset for apply new update?), Windows registry (Configuration exists?).
    if (UI::Fundamental::VersionControl::IsVersionDifference ()) {
        //"Hard-reset data". (If new settings have been added that need to be entered into the data, then we reset the entire value, and delete the key to re-create everything)
        ConfigurationProvider::DoColdPropertiesWakeup (true);
    } else if (RegOpenKeyA (HKEY_CURRENT_USER, CPUID_REG_SYSTEM_DATA_PATH, &ConfigurationProvider::Registry::RegSystemData) != ERROR_SUCCESS || RegOpenKeyA (HKEY_CURRENT_USER, CPUID_REG_CONFIGURATION_DATA_PATH, &ConfigurationProvider::Registry::RegConfigurationData) != ERROR_SUCCESS) {
        //Create new key & fill as default data.
        ConfigurationProvider::DoColdPropertiesWakeup (false);
    }

    //Setup buttons status, run props logic.
    UI::DataWrapper::Configuration::SetupPropertiesHashedObjects ();

}

//Version control.
bool UI::Fundamental::VersionControl::IsVersionDifference () {
    
    //Temp buffer.
    LPDWORD buffer = NULL;
    //Processed result.
    DWORD local = NULL, major = NULL;

    //A little clarification why we use true if an error occurs:
    //We call this function, then we check whether the result is true, if it is, we start a "cold start" while dumping all the data that was before. 
    //This means: we restart the "repository", and the values ​​that are there will correspond to the current build.
    if (RegOpenKeyA (HKEY_CURRENT_USER, CPUID_REG_SYSTEM_DATA_PATH, &ConfigurationProvider::Registry::RegSystemData) == ERROR_SUCCESS) {

        if (RegGetValueA (ConfigurationProvider::Registry::RegSystemData, NULL, "ver.major", RRF_RT_REG_BINARY, NULL, buffer, &major) != ERROR_SUCCESS || RegGetValueA (ConfigurationProvider::Registry::RegSystemData, NULL, "ver.local", RRF_RT_REG_BINARY, NULL, buffer, &local) != ERROR_SUCCESS) {
            return true;
        }

        RegCloseKey (ConfigurationProvider::Registry::RegSystemData);

    } 
    else {
        return true;
    }
    
    //true -> false.
    return !(local == UI::Fundamental::VersionControl::BuildLocalVer && major == UI::Fundamental::VersionControl::BuildMajorVer);

}

//Heartbeat.
void UI::Fundamental::RenderFrameBuffer () {

    //ImGui docs here: https://github.com/ocornut/imgui/tree/master/docs. 
    ImGui::Begin ("##otc-loader-gui", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground);

    {
        //Menu size. By default: 800x600 pixels.
        ImGui::SetWindowSize (ImVec2 (800.f, 600.f));

        //Making render more easier.
        auto draw = ImGui::GetWindowDrawList ();
        auto pos = ImGui::GetWindowPos ();

        /** MAIN MENU RENDER **/

            //Background.
            draw->AddRectFilled (pos, pos + ImVec2 (800.f, 600.f), ImColor (24, 24, 24, 255), 15.f);

            //FIXME: Essentially a crutch that is needed to "change the look of the UI" during the execution of a callback. (p.s Prevents rendering everything except the logo)
            if (!Callback::IsRunning ()) {

                //Tabs background.
                draw->AddRectFilled (pos, pos + ImVec2 (107.f, 600.f), ImColor (54, 54, 54, 54), 15.f, ImDrawCornerFlags_BotLeft | ImDrawCornerFlags_TopLeft);
                //Tabs line.
                draw->AddLine (pos + ImVec2 (107.f, 0.f), pos + ImVec2 (107.f, 600.f), ImColor (53, 53, 53, 105), 1.f);
                //Text at logo.
                draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 18.f, pos + ImVec2 (18.f, 60.f), ImColor (255, 255, 255, 255), "OTC Loader");
                //Current build render.
                draw->AddText (UI::Fundamental::Fonts::NunitoSemiBold, 16.f, pos + ImVec2 (29.5f, 80.f), ImColor (168, 168, 168, 180), std::string (UI::DataWrapper::Language::TranslateMessage ("main.build")).append (std::to_string (UI::Fundamental::VersionControl::BuildMajorVer).append (".").append (std::to_string (UI::Fundamental::VersionControl::BuildLocalVer))).c_str ());
                //Logo box line.
                draw->AddLine (pos + ImVec2 (0.f, 105.f), pos + ImVec2 (107.f, 105.f), ImColor (53, 53, 53, 155), 1.f);

                /** ================ **/

                /** MENU TABS & LEFT TAB RENDER **/

                //Set tab position.                
                ImGui::SetCursorPos (ImVec2 (2.f, 250.f));

                //Create group for sort tabs.
                ImGui::BeginGroup ();

                {
                    //0, 1, 2, 3 -> Icons. More: UI#Fundamental#Fonts#OTCIcons.
                    if (UI::AdvancedRender::RenderTab ("0", UI::DataWrapper::Language::TranslateMessage ("tabs.news"), UI::DataWrapper::Frames::CmpCurrentPage (UI::DataWrapper::Frames::Pages::NEWS), ImVec2 (98.f, 35.5f))) UI::DataWrapper::Frames::SetCurrentPage (UI::DataWrapper::Frames::Pages::NEWS);
                    if (UI::AdvancedRender::RenderTab ("1", UI::DataWrapper::Language::TranslateMessage ("tabs.load"), UI::DataWrapper::Frames::CmpCurrentPage (UI::DataWrapper::Frames::Pages::LOAD), ImVec2 (98.f, 35.5f))) UI::DataWrapper::Frames::SetCurrentPage (UI::DataWrapper::Frames::Pages::LOAD);
                    //Removed due to beta.
                    if (UI::AdvancedRender::RenderTab ("3", UI::DataWrapper::Language::TranslateMessage ("tabs.set"),  UI::DataWrapper::Frames::CmpCurrentPage (UI::DataWrapper::Frames::Pages::SETTINGS), ImVec2 (98.f, 35.5f))) UI::DataWrapper::Frames::SetCurrentPage (UI::DataWrapper::Frames::Pages::SETTINGS);
                }

                //Close group.
                ImGui::EndGroup ();

                //Same, but with language-switchers.
                ImGui::SetCursorPos (ImVec2 (20.f, 560.f));
                ImGui::BeginGroup ();

                {

                    /**
                     *
                     * @point - Fast change region to another, with change all dependency values.
                     * @args  - Region: New region.
                     *
                     * @author - 0x000cb. | 17 / 10 / 20 - 12:49AM.
                     *
                     */

                    auto UpdateRegionDependencyPlaces = [](LanguageProvider::Region region) {

                        //Set new region to local storage.
                        UI::Storage::SystemBuffers::SelectedRegion = region;
                        //Set new region to registry.
                        ConfigurationProvider::SetPropertiesValue (ConfigurationProvider::Properties::DEFAULT_USER_SELECTED_LANG, region);
                        //Flush temp buffers..
                        UI::Storage::FlushCandidateTempBuffers ();

                    };

                    if (UI::AdvancedRender::RenderBox ("EN", UI::DataWrapper::Language::CmpSelectedRegion (LanguageProvider::Region::EN), ImVec2 (36.f, 24.f))) {

                        //Switch to next language in list.
                        switch (UI::DataWrapper::Language::GetSelectedRegion ()) {

                            case LanguageProvider::Region::RU: {

                                UpdateRegionDependencyPlaces (LanguageProvider::Region::EN);

                            }; break;

                        }

                    }

                    //Still render at same line...
                    ImGui::SameLine (0.f, 4.f);
                    if (UI::AdvancedRender::RenderBox ("RU", UI::DataWrapper::Language::CmpSelectedRegion (LanguageProvider::Region::RU), ImVec2 (36.f, 24.f))) {

                        //Switch to next language in list.
                        switch (UI::DataWrapper::Language::GetSelectedRegion ()) {

                            case LanguageProvider::Region::EN: {

                                UpdateRegionDependencyPlaces (LanguageProvider::Region::RU);

                            }; break;

                        }

                    }

                }

                ImGui::EndGroup ();

            }

            /*================*/

                /** MENU ELEMENTS RENDER **/

            ImGui::SetCursorPos (ImVec2 (116.f, 83.f));
            ImGui::BeginGroup ();

            //Logo.
            draw->AddImage (UI::Fundamental::D3X::LogoTexture, pos + ImVec2 (Callback::IsRunning () ? 21.f - 5.f : 31.f, 6.f), pos + ImVec2 (Callback::IsRunning () ? 70.f - 5.f : 80.f, 61.f));

            switch (UI::DataWrapper::Frames::GetCurrentPage ()) {

                case UI::DataWrapper::Frames::Pages::NEWS: {

                    //Last news.
                    draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 22.f, pos + ImVec2 (123.f, 18.f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("news.title"));
                    //About project.
                    draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 22.f, pos + ImVec2 (455.f, 18.f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("news.about"));
                    //Note about clickable links.
                    draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 15.f, pos + ImVec2 (455.f, 40.f), ImColor (255, 255, 255, 120), UI::DataWrapper::Language::TranslateMessage ("news.about.click"));

                    ImGui::SetCursorPos (ImVec2 (120.f, 50.f));

                    ImGui::BeginGroup ();

                    {
                        for (const auto& news : UI::DataWrapper::News::GetInfoAtProvider ()) UI::AdvancedRender::RenderNews (news);
                    }
                
                    ImGui::EndGroup ();

                    ImGui::SetCursorPos (ImVec2 (453.f, 62.f));
                    ImGui::BeginGroup ();

                    {

                        ImGui::PushStyleVar (ImGuiStyleVar_ItemSpacing, ImVec2 (0.f, 0.f));
                        
                        //Info about project.
                        ImGui::BeginChild ("##info", ImVec2 (328.f, 248.f), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

                        {
                            UI::AdvancedRender::RenderHeaderText (UI::Fundamental::Fonts::NunitoExtraBold, 18.f, ImColor (255, 255, 255, 195), UI::DataWrapper::Language::TranslateMessage ("news.info"));
                            ImGui::Spacing ();
                            UI::AdvancedRender::RenderText (ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("news.info.txt"));
                        }

                        ImGui::EndChild ();

                        ImGui::Dummy (ImVec2 (0.f, 12.f));

                        //Contacts [Community].
                        UI::AdvancedRender::RenderContactInteractiveBoxCase ("##contactscomm", UI::DataWrapper::Language::TranslateMessage ("news.con.com"), {

                            { UI::DataWrapper::Language::TranslateMessage ("news.con.com.dis"),  "https://discord.gg/GUcRJT8",             },
                            { UI::DataWrapper::Language::TranslateMessage ("news.con.com.mail"), "mailto:otc-community@protonmail.com",    },

                        }, ImVec2 (180.f, 75.f));

                        ImGui::SameLine (0, 10);

                        //Contacts. [Developer]
                        UI::AdvancedRender::RenderContactInteractiveBoxCase ("##contactsdev", UI::DataWrapper::Language::TranslateMessage ("news.con.dev"), {

                            { UI::DataWrapper::Language::TranslateMessage ("news.con.dev.vk"),  "https://www.vk.com/0xb00b1e5",   },
                            { UI::DataWrapper::Language::TranslateMessage ("news.con.dev.dis"), "https://discord.gg/NdnbBsX",     },
                            { UI::DataWrapper::Language::TranslateMessage ("news.con.dev.tg"),  "https://www.t.me/cpuid",         }

                        }, ImVec2 (138.f, 90.f));

                        ImGui::Dummy (ImVec2 (0.f, 10.f));
                        ImGui::SetCursorPosX (ImGui::GetCursorPosX () + 190.f);

                        //Donate. <3
                        UI::AdvancedRender::RenderContactInteractiveBoxCase ("##support", UI::DataWrapper::Language::TranslateMessage ("news.support"), {

                                { "Paypal.",    "https://paypal.me/payotc",       },
                                { "Qiwi.",      "https://qiwi.com/p/79013362301", },
                                { "BTC.",       "https://pastebin.com/SdqiNMxu",  }

                        }, ImVec2 (138.f, 90.f));

                        ImGui::PopStyleVar ();
                    }

                    ImGui::EndGroup ();

                } break;

                case UI::DataWrapper::Frames::Pages::LOAD:

                    if (!Callback::IsRunning ()) {

                        //Page square.
                        draw->AddRect (pos + ImVec2 (205.f, 18.f), pos + ImVec2 (240.f, 43.f), ImColor (255, 255, 255, 20), 2.f);
                        //Page counter.
                        draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 16.f, pos + ImVec2 (213.f, 22.5f), ImColor (255, 255, 255, 140), std::string (std::to_string (UI::DataWrapper::Frames::GetCurrentLoadPage () + 1)).append ("/3").c_str ());

                        //Button square.
                        draw->AddRectFilled (pos + ImVec2 (117.f, 18.f), pos + ImVec2 (196.f, 43.f), ImColor (255, 255, 255, 56), 2.f);

                        ImGui::SetCursorPos (ImVec2 (248.f, 18.f));
                        ImGui::BeginGroup ();

                        {

                            if (!UI::DataWrapper::Frames::CmpCurrentLoadPage (UI::DataWrapper::Frames::LoadPages::README) && Callback::Status == Callback::CallType::_WAIT) {

                                if (UI::AdvancedRender::RenderPage ("##prev", ImVec2 (24.f, 24.f), 0)) UI::DataWrapper::Frames::IncCurrentLoadPage (true);
                                ImGui::SameLine (0.f, 5.f);

                            }

                            if (!UI::DataWrapper::Frames::CmpCurrentLoadPage (UI::DataWrapper::Frames::LoadPages::SEGMENT)) {

                                if (UI::AdvancedRender::RenderPage ("##next", ImVec2 (24.f, 24.f), 1)) UI::DataWrapper::Frames::IncCurrentLoadPage (false);

                            }

                        }

                        ImGui::EndGroup ();

                    }


                        //Sub-pages of load page.
                        switch (UI::DataWrapper::Frames::GetCurrentLoadPage ()) {

                            case UI::DataWrapper::Frames::LoadPages::README: {

                                //Page name.
                                draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 16.f, pos + ImVec2 (132.f, 22.5f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("load.rm.name"));

                                ImGui::SetCursorPos (ImVec2 (118.f, 65.f));
                                ImGui::BeginChild ("##readme", ImVec2 (665.f, 510.f), true);

                                {

                                    //Uni-solution.
                                    auto RendererQAText = [] (const char* question, std::vector <const char*> answer) {
                                    
                                        UI::AdvancedRender::RenderText (ImColor (159, 57, 57, 255), std::string ("    -> ").append (question).c_str ());

                                        for (const auto& ans : answer) {
                                            UI::AdvancedRender::RenderText (ImColor (255, 255, 255, 255), std::string ("        <- ").append (ans).append ("\n").c_str ());
                                        }

                                        ImGui::Dummy (ImVec2 (0.f, 2.f));

                                    };

                                    //Alert about injector.
                                    UI::AdvancedRender::RenderHeaderText (UI::Fundamental::Fonts::NunitoExtraBold, 17.f, ImColor (200, 64, 64, 153), UI::DataWrapper::Language::TranslateMessage ("load.rm.imp"));
    
                                    ImGui::NewLine ();

                                    //FAQ.
                                    UI::AdvancedRender::RenderHeaderText (UI::Fundamental::Fonts::NunitoExtraBold, 17.f, ImColor (255, 255, 255, 255), LanguageProvider::GetRegionalMessageFromBuffer (LanguageProvider::Region::EN, LanguageProvider::BufferType::UI, "load.rm.rg"));
                                    ImGui::Dummy (ImVec2 (0.f, 4.f));

                                    ImGui::PushFont (UI::Fundamental::Fonts::NunitoBold);

                                    //Common issues & solutions.
                                    RendererQAText (UI::DataWrapper::Language::TranslateMessage ("load.rm.is.render"), { UI::DataWrapper::Language::TranslateMessage ("load.rm.is.render.slo"), UI::DataWrapper::Language::TranslateMessage ("load.rm.is.render.sls") });
                                    RendererQAText (UI::DataWrapper::Language::TranslateMessage ("load.rm.is.crash"),  { UI::DataWrapper::Language::TranslateMessage ("load.rm.is.crash.slo"), UI::DataWrapper::Language::TranslateMessage ("load.rm.is.crash.sls") });
                                    RendererQAText (UI::DataWrapper::Language::TranslateMessage ("load.rm.is.bug"),    { UI::DataWrapper::Language::TranslateMessage ("load.rm.is.bug.slo"), UI::DataWrapper::Language::TranslateMessage ("load.rm.is.bug.sls"), UI::DataWrapper::Language::TranslateMessage ("load.rm.is.bug.slt") });

                                    ImGui::Dummy (ImVec2 (0.f, 4.f));

                                    //Cheat problems.
                                    UI::AdvancedRender::RenderText (ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("load.rm.ik.name"));
                                    UI::AdvancedRender::RenderText (ImColor (159, 57, 57, 255), UI::DataWrapper::Language::TranslateMessage ("load.rm.ik.ls"));

                                    ImGui::Dummy (ImVec2 (0.f, 8.f));

                                    //Special thanks.
                                    UI::AdvancedRender::RenderText (ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("load.rm.tx.name"));

                                    //Special thanks.
                                    RendererQAText (UI::DataWrapper::Language::TranslateMessage ("load.rm.tx.dv"), { UI::DataWrapper::Language::TranslateMessage ("load.rm.tx.dvl") });
                                    RendererQAText (UI::DataWrapper::Language::TranslateMessage ("load.rm.tx.ds"), { UI::DataWrapper::Language::TranslateMessage ("load.rm.tx.dsl") });
                                    RendererQAText (UI::DataWrapper::Language::TranslateMessage ("load.rm.tx.ts"), { UI::DataWrapper::Language::TranslateMessage ("load.rm.tx.tsl") });

                                    //Thx to user.
                                    ImGui::Dummy (ImVec2 (0.f, 8.f));

                                    UI::AdvancedRender::RenderText (ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("load.rm.tx.ur"));

                                    ImGui::PopFont ();

                                }

                                ImGui::EndChild ();

                            } break;

                            case UI::DataWrapper::Frames::LoadPages::ADDONS: {

                                //FIXME: Todo create wrapper for support multilang centering.
                                //Page name.
                                draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 16.f, pos + ImVec2 (!UI::DataWrapper::Language::CmpSelectedRegion (LanguageProvider::Region::RU) ? 130.f : 128.f, 22.5f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("load.ad.name"));
                                //Before oep queue
                                draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 22.f, pos + ImVec2 (116.f, 65.f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("load.ad.oep.bef"));
                                //After oep queue.
                                draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 22.f, pos + ImVec2 (453.f, 65.f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("load.ad.oep.aft"));

                                auto RendererModulesActionPanels = [] (UI::DataWrapper::Load::OEPType oep, const char* buttonAdd, const char* buttonRemove, const char* windowTitle, const char* fileType) {

                                       /**
                                        *
                                        * @point   - Open dialog window for pick addon file.
                                        * @example - TryInputFile ("Select a file", "JSON\0*.json\0", array);
                                        * @args    - Title: Dialog window title, Executable: File fitler & separator, File: Array for write file path.
                                        *
                                        * @author - 0x000cb | 17 / 08 / 2020 - 10:40PM.
                                        *
                                        **/

                                        auto TryInputFile = [] (const char* title, const char* executable, char file []) {

                                            OPENFILENAMEA openFileName;
                     
                                            ZeroMemory (&openFileName, sizeof (openFileName));
                     
                                            openFileName.lStructSize   = sizeof (openFileName);
                                            openFileName.hwndOwner     = NULL;
                                            openFileName.lpstrTitle    = title;
                                            openFileName.lpstrFilter   = executable;
                                            openFileName.lpstrFile     = file;
                                            openFileName.nMaxFile      = MAX_PATH;
                                            openFileName.nMaxFileTitle = MAX_PATH;
                                            openFileName.Flags         = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
                     
                                            return GetOpenFileNameA (&openFileName);
                                        };

                                        std::vector <std::string> queue = UI::DataWrapper::Load::GetFilePathToAddon (oep);

                                        if (!queue.empty ()) {

                                            ImGui::SetCursorPosY (10.f);
                                           
                                            for (int modulesIterator = 0; modulesIterator < static_cast <int> (queue.size ()); modulesIterator++) {
                                                ImGui::SetCursorPosX (9.f);
                                                UI::AdvancedRender::RenderText (ImColor(255.f, 255.f, 255.f, 205.f), (std::string ("#").append (std::to_string (modulesIterator + 1)).append (" -> ") + queue.at (modulesIterator)).c_str ());
                                            }

                                            ImGui::SetCursorPosY (413.f);
                                        }
                                    
                                        //So, first button (add) render only if queue.size () <= 17, second button (remove) only if queue.size () > 0.
                                        //We just set a condition on which two buttons will work, but if one of them did not work (not pass condition == not rendered), 
                                        //then we put the cursor by X at the position to render only one button.
                                        ImGui::SetCursorPosX (queue.size () > 0 && queue.size () <= 17 ? 10.5f : 95.5f);

                                        if (queue.size () <= 17) {

                                            if (ImGui::Button (buttonAdd, ImVec2 (150.f, 24.f))) {

                                                char output [MAX_PATH];
                                                ZeroMemory (&output, sizeof (output));

                                                if (TryInputFile (windowTitle, fileType, output)) {

                                                    if (std::find (queue.begin (), queue.end (), output) == queue.end ()) UI::DataWrapper::Load::GetFilePathToAddon (oep).emplace_back (output); 

                                                }

                                            };

                                            ImGui::SameLine ();

                                        }

                                        if (queue.size () > 0) {

                                            if (ImGui::Button (buttonRemove, ImVec2 (150.f, 24.f))) {
                                                if (!queue.empty()) UI::DataWrapper::Load::GetFilePathToAddon (oep).pop_back ();
                                            };

                                        }

                                };

                                ImGui::SetCursorPosY (100.f);
                                ImGui::BeginChild ("##before", ImVec2 (329.f, 450.f), true);

                                {
                                   RendererModulesActionPanels (UI::DataWrapper::Load::OEPType::BEFORE, 
                                                                UI::DataWrapper::Language::TranslateMessage ("load.ad.mod.add"), 
                                                                UI::DataWrapper::Language::TranslateMessage ("load.ad.mod.rem"), 
                                                                UI::DataWrapper::Language::TranslateMessage ("load.ad.win.titl"), 
                                                                UI::DataWrapper::Language::TranslateMessage ("load.ad.win.type"));
                                }

                                ImGui::EndChild ();
                                ImGui::SameLine ();

                                ImGui::BeginChild ("##after", ImVec2 (329.f, 450.f), true);

                                {
                                    RendererModulesActionPanels (UI::DataWrapper::Load::OEPType::AFTER, 
                                                                 UI::DataWrapper::Language::TranslateMessage ("load.ad.mod.add"), 
                                                                 UI::DataWrapper::Language::TranslateMessage ("load.ad.mod.rem"), 
                                                                 UI::DataWrapper::Language::TranslateMessage ("load.ad.win.titl"),
                                                                 UI::DataWrapper::Language::TranslateMessage ("load.ad.win.type"));
                                }

                                ImGui::EndChild ();

                            } break;

                            case UI::DataWrapper::Frames::LoadPages::SEGMENT: {

                                if (!Callback::IsRunning ()) {

                                    //Page name.
                                    draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 16.f, pos + ImVec2 (129.f, 22.5f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("load.seg.name"));

                                    ImGui::SetCursorPos (ImVec2 (660.f, 18.f));
                                
                                    //Output console.
                                    draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 22.f, pos + ImVec2 (116.f, 55.f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("load.seg.out"));
                                    ImGui::SetCursorPos (ImVec2 (116.f, 85.f));

                                }
                                else {

                                    draw->AddText (UI::Fundamental::Fonts::SourceCodeProLight, 30.f, pos + ImVec2 (65.f, 16.f), ImColor (255, 255, 255, 125), "|");
                                    draw->AddText (UI::Fundamental::Fonts::NunitoBold, 18.f, pos + ImVec2 (80.f, 25.f), ImColor (255, 255, 255, 200), UI::DataWrapper::Language::TranslateMessage ("load.seg.clbck"));
                                    
                                    if (UI::DataWrapper::Load::GetCurrentLoadBufferOutputPage () == UI::Fundamental::Buffers::TEMP_LOAD_DEBUG) draw->AddText (UI::Fundamental::Fonts::NunitoBold, 15.f, pos + ImVec2 (81.f, 42.f), ImColor (200, 64, 64, 200), UI::DataWrapper::Language::TranslateMessage ("load.seg.dbg"));
                                    
                                    ImGui::SetCursorPos (((ImGui::GetWindowSize () - ImVec2 (670.f, 499.f)) * 0.5f) + ImVec2 (5.f, 20.f));
                                }

                                ImGui::BeginChild ("##output", ImVec2 (670.f, 499.f), true);

                                {

                                    switch (Callback::Status) {

                                        case Callback::CallType::_WAIT:

                                           //Common info render.
                                           ImGui::Dummy (ImVec2 (4.f, 5.f));
                                           ImGui::Text (UI::DataWrapper::Language::TranslateMessage ("load.seg.evn"));

                                        break;

                                        case Callback::CallType::_IN:
                                        case Callback::CallType::_PRE_OUT:

                                            for (const auto& text : UI::DataWrapper::Load::GetMessagesFromLdOutput (UI::DataWrapper::Load::GetCurrentLoadBufferOutputPage ())) {
                                                UI::AdvancedRender::RenderOutputText (text.m_prefix, text.m_message.c_str ());
                                            }

                                        break;

                                        case Callback::CallType::_OUT:

                                           UI::AdvancedRender::RenderHeaderText (UI::Fundamental::Fonts::NunitoExtraBold, 16.f, ImColor (255, 255, 255, 175), UI::DataWrapper::Language::TranslateMessage ("load.seg.cmp"));

                                        break;

                                    }
                                }
    
                                ImGui::EndChild ();

                            } break; //case LoadPages::SEGMENT.

                    } break; //case Pages::LOAD.

                case UI::DataWrapper::Frames::Pages::SETTINGS: {

                    //PAGE COMMON RENDER ROUTINE.
                    //Draw button with page name.
                    draw->AddRectFilled (pos + ImVec2 (117.f, 18.f), pos + ImVec2 (196.f, 43.f), ImColor (255, 255, 255, 56), 2.f);

                    //FIXME: Todo create wrapper for support multilang centering.
                    draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 16.f, pos + ImVec2 (!UI::DataWrapper::Language::CmpSelectedRegion (LanguageProvider::Region::RU) ? 133.f : 126.f, 22.5f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("sett.name"));

                    ImGui::SetCursorPosY (230.f);
                    //Draw "user-mode" text to rect position.
                    draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 22.f, ImVec2 (pos.x, pos.y + 140.f) + ImVec2 (116.f, 55.f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("sett.mod.us"));
                    //Same but with different X position.
                    draw->AddText (UI::Fundamental::Fonts::NunitoExtraBold, 22.f, ImVec2 (pos.x, pos.y + 140.f) + ImVec2 (453.f, 55.f), ImColor (255, 255, 255, 255), UI::DataWrapper::Language::TranslateMessage ("sett.mod.dv"));

                    //Pretty hardcoded thing.
                    ImGui::BeginChild ("##user-mode", ImVec2 (329.f, 200.f), true);

                    {

                        if (ImGui::Checkbox (LanguageProvider::GetRegionalMessageFromBuffer (LanguageProvider::Region::EN, LanguageProvider::BufferType::UI, "sett.us.disrpc"), &UI::DataWrapper::Frames::GetLocalHashedReferencedObject (ConfigurationProvider::PropertiesToText (ConfigurationProvider::Properties::DEFAULT_USER_DISCORD_RPC)))) {
                            ConfigurationProvider::SetPropertiesDifferencialValue (ConfigurationProvider::Properties::DEFAULT_USER_DISCORD_RPC);

                            if (!ConfigurationProvider::GetPropertiesValue (ConfigurationProvider::Properties::DEFAULT_USER_DISCORD_RPC)) {
                                //Shutdown rpc.
                                Discord_ClearPresence ();
                                Discord_Shutdown ();
                            } else {
                                //Init rpc.
                                DiscordRPC::SetupDefaultRPC ("[~]", "logo", UI::DataWrapper::Language::TranslateMessage ("sett.us.disrpc.pw"));
                                DiscordRPC::SetRpcState (UI::DataWrapper::Language::TranslateMessage (Callback::Status == Callback::CallType::_WAIT ? "sett.us.disrpc.in" : "sett.us.disrpc.gm"));
                            }

                        };

                    }

                    ImGui::EndChild ();
                    ImGui::SameLine ();

                    ImGui::BeginChild ("##developer-mode", ImVec2 (329.f, 200.f), true);
                    
                    {

                        if (ImGui::Checkbox (UI::DataWrapper::Language::TranslateMessage ("sett.dv.dbgload"), &UI::DataWrapper::Frames::GetLocalHashedReferencedObject (ConfigurationProvider::PropertiesToText (ConfigurationProvider::Properties::DEFAULT_DEV_DEBUG_LOAD)))) {
                            ConfigurationProvider::SetPropertiesDifferencialValue (ConfigurationProvider::Properties::DEFAULT_DEV_DEBUG_LOAD); 
                            UI::Storage::SystemBuffers::Frames::Pages.at ("load.seg.out.type") = ConfigurationProvider::GetPropertiesValue (ConfigurationProvider::Properties::DEFAULT_DEV_DEBUG_LOAD) ? UI::Fundamental::Buffers::TEMP_LOAD_DEBUG : UI::Fundamental::Buffers::TEMP_LOAD_INFO;
                        };

                    }

                    ImGui::EndChild ();

                } break;
            }

            ImGui::EndGroup ();

         }

    ImGui::End ();
}






//---- BEGIN WRAPPERS FOR LANGUAGE ----

const char* UI::DataWrapper::Language::TranslateMessage (std::string path) {
    return LanguageProvider::GetRegionalMessageFromBuffer (UI::Storage::SystemBuffers::SelectedRegion, LanguageProvider::BufferType::UI, path);
};

bool UI::DataWrapper::Language::CmpSelectedRegion (LanguageProvider::Region target) {
    return target == UI::Storage::SystemBuffers::SelectedRegion;
}

LanguageProvider::Region UI::DataWrapper::Language::GetSelectedRegion () {
    return UI::Storage::SystemBuffers::SelectedRegion;
}

// ---- END WRAPPERS FOR LANGUAGE ----

// -------

// ---- BEGIN WRAPPERS FOR NEWS ----

std::vector <UI::DataWrapper::News::DayNews> UI::DataWrapper::News::GetInfoAtProvider () {
    return UI::Storage::TextBuffers::NewsData.at (UI::Storage::SystemBuffers::SelectedRegion);
}

const char* UI::DataWrapper::News::TypeToText (UI::DataWrapper::News::Type type) {

    switch (type) {

        default:
        case UI::DataWrapper::News::Type::LOADER: return UI::DataWrapper::Language::TranslateMessage ("news.type.load");
        case UI::DataWrapper::News::Type::OTC:    return LanguageProvider::GetRegionalMessageFromBuffer (LanguageProvider::Region::EN, LanguageProvider::BufferType::UI, "news.type.otc");

    }

}

const char* UI::DataWrapper::News::CategoryToText (UI::DataWrapper::News::Category category) {

    switch (category) {

        default:
        case UI::DataWrapper::News::Category::ADDED:    return UI::DataWrapper::Language::TranslateMessage ("news.ctg.add");
        case UI::DataWrapper::News::Category::REWORKED: return UI::DataWrapper::Language::TranslateMessage ("news.ctg.rew");
        case UI::DataWrapper::News::Category::REMOVED:  return UI::DataWrapper::Language::TranslateMessage ("news.ctg.rem");
        case UI::DataWrapper::News::Category::IMPROVED: return UI::DataWrapper::Language::TranslateMessage ("news.ctg.imp");

    }

}

// ---- END WRAPPERS FOR NEWS ----

// -------

// ---- START WRAPPERS FOR LOAD ----

UI::Fundamental::Buffers UI::DataWrapper::Load::GetCurrentLoadBufferOutputPage () {
    return static_cast <UI::Fundamental::Buffers> (UI::Storage::SystemBuffers::Frames::Pages.at ("load.seg.out.type"));
}

void UI::DataWrapper::Load::SetCurrentLoadBufferOutputPage (UI::Fundamental::Buffers buffer) {
    UI::Storage::SystemBuffers::Frames::Pages.at ("load.seg.out.type") = buffer;
}

Concurrency::concurrent_vector <UI::DataWrapper::PrefixedText> UI::DataWrapper::Load::GetMessagesFromLdOutput (UI::Fundamental::Buffers buffer) {

    switch (buffer) {

       default:
       case UI::Fundamental::Buffers::TEMP_LOAD_INFO:  return UI::Storage::TempBuffers::Load::Info;
       case UI::Fundamental::Buffers::TEMP_LOAD_DEBUG: return UI::Storage::TempBuffers::Load::Debug;

    }

}

void UI::DataWrapper::Load::PutMessageToLdOutput (const char* prefix, std::string path) {

    switch (UI::DataWrapper::Load::GetCurrentLoadBufferOutputPage ()) {

       default:
       case UI::Fundamental::Buffers::TEMP_LOAD_INFO:  {
           UI::Storage::TempBuffers::Load::Info.push_back (UI::DataWrapper::PrefixedText { prefix, LanguageProvider::GetRegionalMessageFromBuffer (UI::DataWrapper::Language::GetSelectedRegion (), LanguageProvider::BufferType::PRIMAL, path) });
       } break;

       case UI::Fundamental::Buffers::TEMP_LOAD_DEBUG: {
           UI::Storage::TempBuffers::Load::Debug.push_back (UI::DataWrapper::PrefixedText { prefix, LanguageProvider::GetRegionalMessageFromBuffer (UI::DataWrapper::Language::GetSelectedRegion (), LanguageProvider::BufferType::PRIMAL, path.append (".dbg")) });
       } break;

    }
   
}

std::vector <std::string>& UI::DataWrapper::Load::GetFilePathToAddon (UI::DataWrapper::Load::OEPType provider) {
    return UI::Storage::TempBuffers::Load::Addons.at (provider);
}

void UI::DataWrapper::Frames::IncCurrentLoadPage (bool reversed) {
    reversed ? UI::Storage::SystemBuffers::Frames::Pages.at ("load.page") -- : UI::Storage::SystemBuffers::Frames::Pages.at ("load.page") ++;
}

bool UI::DataWrapper::Frames::CmpCurrentLoadPage (UI::DataWrapper::Frames::LoadPages target) {
    return target <= UI::DataWrapper::Frames::LoadPages::SEGMENT && target == UI::Storage::SystemBuffers::Frames::Pages.at ("load.page");
}

void UI::DataWrapper::Frames::SetCurrentLoadPage (UI::DataWrapper::Frames::LoadPages page) {
    UI::Storage::SystemBuffers::Frames::Pages.at ("load.page") = page;
}

int UI::DataWrapper::Frames::GetCurrentLoadPage () {
    return UI::Storage::SystemBuffers::Frames::Pages.at ("load.page");
}

// ---- END WRAPPERS FOR LOAD ----

// -------

// ---- BEGIN WRAPPERS FOR FRAMES ----

int UI::DataWrapper::Frames::GetCurrentPage () {
    return UI::Storage::SystemBuffers::Frames::Pages.at ("menu.page");
}

void UI::DataWrapper::Frames::SetCurrentPage (UI::DataWrapper::Frames::Pages page) {
    UI::Storage::SystemBuffers::Frames::Pages.at ("menu.page") = page;
}

bool UI::DataWrapper::Frames::GetLocalHashedObject (std::string object) {
    return UI::DataWrapper::Frames::GetLocalHashedReferencedObject (object);
}

bool& UI::DataWrapper::Frames::GetLocalHashedReferencedObject (std::string object) {

    if (UI::Storage::SystemBuffers::Frames::LocalObjectsStatus.find (object) == UI::Storage::SystemBuffers::Frames::LocalObjectsStatus.end ()) UI::DataWrapper::Frames::SetLocalHashedObjectStatus (object, false, true);

    return UI::Storage::SystemBuffers::Frames::LocalObjectsStatus.at (object);

}

void UI::DataWrapper::Frames::SetLocalHashedObjectStatus (std::string object, bool value, bool isEmplace) {

    if (object.size () == 0) return;

    if (isEmplace) {
        UI::Storage::SystemBuffers::Frames::LocalObjectsStatus.emplace (object, value);
    }
    else {
        UI::Storage::SystemBuffers::Frames::LocalObjectsStatus.at (object) = value;
    }

}

bool UI::DataWrapper::Frames::CmpCurrentPage (UI::DataWrapper::Frames::Pages target) {
    return target <= UI::DataWrapper::Frames::Pages::SETTINGS && target == UI::Storage::SystemBuffers::Frames::Pages.at ("menu.page");
}

void UI::DataWrapper::Frames::IncCurrentPage (bool reversed) {
    reversed ? UI::Storage::SystemBuffers::Frames::Pages.at ("menu.page") -- : UI::Storage::SystemBuffers::Frames::Pages.at ("menu.page") ++;
}

// ---- END WRAPPERS FOR FRAMES ----

// ---- BEGIN WRAPPERS FOR CONFIGURATION ---

void UI::DataWrapper::Configuration::SetupPropertiesHashedObjects () {

    //Refactoring and move to UIRenderer.[cpp/hpp]
    for (const auto& prop : ConfigurationProvider::GetUserPropertiesList ()) {

        switch (prop) {

            case ConfigurationProvider::Properties::DEFAULT_DEV_DEBUG_LOAD: {


                if (ConfigurationProvider::GetPropertiesValue (prop) && UI::DataWrapper::Load::GetCurrentLoadBufferOutputPage () == UI::Fundamental::Buffers::TEMP_LOAD_INFO) {
                    UI::Storage::SystemBuffers::Frames::Pages.at ("load.seg.out.type") = UI::Fundamental::Buffers::TEMP_LOAD_DEBUG;
                }

            }; break;

            case ConfigurationProvider::Properties::DEFAULT_USER_SELECTED_LANG: {

                    UI::Storage::SystemBuffers::SelectedRegion = static_cast <LanguageProvider::Region> (ConfigurationProvider::GetPropertiesValue (prop));

            }; break;

            case ConfigurationProvider::Properties::DEFAULT_USER_DISCORD_RPC: {

                if (ConfigurationProvider::GetPropertiesValue (prop)) {
                    DiscordRPC::SetupDefaultRPC ("[~]", "logo", UI::DataWrapper::Language::TranslateMessage ("sett.us.disrpc.pw"));
                }

            }; break;

        }

        //Setup button status. (Enable/disable)
        if (prop != ConfigurationProvider::Properties::DEFAULT_USER_SELECTED_LANG) UI::DataWrapper::Frames::SetLocalHashedObjectStatus (ConfigurationProvider::PropertiesToText (prop), ConfigurationProvider::GetPropertiesValue (prop), true);

    }

}

// ---- END WRAPPERS FOR CONFIGURATION ---

// -------

// ---- BEGIN WRAPPERS FOR STORAGE ----

void UI::Storage::FlushCandidateTempBuffers () {

    if (Callback::Status == Callback::CallType::_OUT) {
        UI::Storage::TempBuffers::Load::Addons.clear ();
        (UI::DataWrapper::Load::GetCurrentLoadBufferOutputPage () == UI::Fundamental::Buffers::TEMP_LOAD_INFO ? UI::Storage::TempBuffers::Load::Info : UI::Storage::TempBuffers::Load::Debug).clear ();
    }

}

// ---- END WRAPPERS FOR STORAGE ----

// -------

// ---- BEGIN WRAPPERS FOR ADVANCED RENDER ----

//Simplify render. Just helpers.
bool UI::AdvancedRender::RenderTabEx (const char* icon, const char* label, const bool active, const ImVec2& argSize, ImGuiButtonFlags flags) {

    ImGuiWindow* window = ImGui::GetCurrentWindow ();
    if (window->SkipItems) return false;

    ImGuiContext& context  = *GImGui;
    const ImGuiStyle& style = context.Style;
    const ImGuiID id = window->GetID (label);
    const ImVec2 labelSize = ImGui::CalcTextSize (label, NULL, true);

    ImVec2 pos = window->DC.CursorPos;
    if ((flags & ImGuiButtonFlags_AlignTextBaseLine) && style.FramePadding.y < window->DC.CurrLineTextBaseOffset) pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;
    
    ImVec2 size = ImGui::CalcItemSize (argSize, labelSize.x + style.FramePadding.x * 2.0f, labelSize.y + style.FramePadding.y * 2.0f);

    const ImRect rect (pos, pos + size);

    ImGui::ItemSize (size, style.FramePadding.y);
    if (!ImGui::ItemAdd (rect, id)) return false;
    if (window->DC.ItemFlags & ImGuiItemFlags_ButtonRepeat) flags |= ImGuiButtonFlags_Repeat;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior (rect, id, &hovered, &held, flags);
        
    //Render.
    window->DrawList->AddText (UI::Fundamental::Fonts::SysIcons, 20.f, rect.Min + ImVec2 (9.5f, 9.f), active || hovered ? ImColor (200, 64, 64, 255) : ImColor (255, 255, 255, 185), icon);
    window->DrawList->AddText (UI::Fundamental::Fonts::NunitoSemiBold, 16.f, rect.Min + ImVec2 (35.f, 11.f), active || hovered ? ImColor (255, 255, 255, 255) : ImColor (255, 255, 255, 220), label);
 
    return pressed;
}

bool UI::AdvancedRender::RenderPageEx (const char* label, const ImVec2& argSize, ImGuiButtonFlags flags, const int dir) {

    ImGuiWindow* window = ImGui::GetCurrentWindow ();
    if (window->SkipItems) return false;

    ImGuiContext& context = *GImGui;
    const ImGuiStyle& style = context.Style;
    const ImGuiID id = window->GetID (label);
    const ImVec2 labelSize = ImGui::CalcTextSize (label, NULL, true);

    ImVec2 pos = window->DC.CursorPos;
    if ((flags & ImGuiButtonFlags_AlignTextBaseLine) && style.FramePadding.y < window->DC.CurrLineTextBaseOffset) pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;

    ImVec2 size = ImGui::CalcItemSize (argSize, labelSize.x + style.FramePadding.x * 2.0f, labelSize.y + style.FramePadding.y * 2.0f);

    const ImRect rect (pos, pos + size);

    ImGui::ItemSize (size, style.FramePadding.y);
    if (!ImGui::ItemAdd (rect, id)) return false;
    if (window->DC.ItemFlags & ImGuiItemFlags_ButtonRepeat) flags |= ImGuiButtonFlags_Repeat;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior (rect, id, &hovered, &held, flags);

    //Render a rectangle.
    window->DrawList->AddRect (rect.Min, rect.Max, ImColor (53, 53, 53, 255), 2.f);

    //Render.
    if (hovered) {
        //Red square.
        window->DrawList->AddRectFilled (rect.Min, rect.Max, ImColor (159, 57, 57, 255), 2.f);
        //Arrow with different pose.
        ImGui::RenderArrow (window->DrawList, rect.Min + (dir == 0 ? ImVec2 (3.f, 4.f) : ImVec2 (5.f, 4.f)), ImColor (255, 255, 255, 255), dir == 0 ? ImGuiDir_Left : ImGuiDir_Right);
    } else {
        //Similar, but without the square.
        ImGui::RenderArrow (window->DrawList, rect.Min + (dir == 0 ? ImVec2 (3.f, 4.f) : ImVec2 (5.f, 4.f)), ImColor (255, 255, 255, 140), dir == 0 ? ImGuiDir_Left : ImGuiDir_Right);
    }

    return pressed;
}

bool UI::AdvancedRender::RenderBoxEx (const char* label, const bool active, const ImVec2& argSize, ImGuiButtonFlags flags) {

    ImGuiWindow* window = ImGui::GetCurrentWindow ();
    if (window->SkipItems)
        return false;

    ImGuiContext& context = *GImGui;
    const ImGuiStyle& style = context.Style;
    const ImGuiID id = window->GetID (label);
    const ImVec2 labelSize = ImGui::CalcTextSize (label, NULL, true);

    ImVec2 pos = window->DC.CursorPos;
    if ((flags & ImGuiButtonFlags_AlignTextBaseLine) && style.FramePadding.y < window->DC.CurrLineTextBaseOffset) pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;

    ImVec2 size = ImGui::CalcItemSize (argSize, labelSize.x + style.FramePadding.x * 2.0f, labelSize.y + style.FramePadding.y * 2.0f);

    const ImRect rect (pos, pos + size);

    ImGui::ItemSize (size, style.FramePadding.y);
    if (!ImGui::ItemAdd (rect, id)) return false;
    if (window->DC.ItemFlags & ImGuiItemFlags_ButtonRepeat) flags |= ImGuiButtonFlags_Repeat;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior (rect, id, &hovered, &held, flags);

    //Outline.
    window->DrawList->AddRect (rect.Min, rect.Max, ImColor (53, 53, 53, 255), 2.f);
    ImGui::PushStyleColor (ImGuiCol_Text, ImVec4 (1.00f, 1.00f, 1.00f, active ? 1.f : 0.55f));

    //Render.
    if (active) {
        //Red square.
        window->DrawList->AddRectFilled (rect.Min, rect.Max, ImColor (159, 57, 57, 255), 2.f);
        //Text render.
        ImGui::RenderTextClipped (rect.Min + style.FramePadding, rect.Max - style.FramePadding, label, NULL, &labelSize, style.ButtonTextAlign, &rect);
    } else {
        //Similar, but without the square.
        ImGui::RenderTextClipped (rect.Min + style.FramePadding, rect.Max - style.FramePadding, label, NULL, &labelSize, style.ButtonTextAlign, &rect);
    }

    ImGui::PopStyleColor (); //For stop changing color.

    return pressed;
}

bool UI::AdvancedRender::RenderTab (const char* icon, const char* label, const bool active, const ImVec2& argSize) {
    return UI::AdvancedRender::RenderTabEx (icon, label, active, argSize, 0);
}

bool UI::AdvancedRender::RenderPage (const char* label, const ImVec2& argSize, const int dir) {
    return UI::AdvancedRender::RenderPageEx (label, argSize, 0, dir);
}

bool UI::AdvancedRender::RenderBox (const char* label, const bool active, const ImVec2& argSize) {
    return UI::AdvancedRender::RenderBoxEx (label, active, argSize, 0);
}

void UI::AdvancedRender::RenderHeaderText (const ImFont* font, float fontSize, ImColor color, const char* text) {

    ImGuiWindow* window = ImGui::GetCurrentWindow ();

    const float wrapWidth = window->DC.TextWrapPos >= 0.0f ? ImGui::CalcWrapWidthForPos (window->DC.CursorPos, window->DC.TextWrapPos) : 0.0f;

    const ImVec2 textPosition (window->DC.CursorPos.x, window->DC.CursorPos.y + window->DC.CurrLineTextBaseOffset), textSize = ImGui::CalcTextSize (text, NULL, false, wrapWidth);

    //Calc text pos.
    ImRect rect (textPosition, textPosition + textSize);

    //For indent.
    ImGui::ItemSize (textSize + ImVec2 (0.f, 5.f), 0.0f);
    if (!ImGui::ItemAdd (rect, 0)) return;

    //Text render.
    window->DrawList->AddText (font, fontSize, rect.Min, color, text);
}

void UI::AdvancedRender::RenderText (ImColor color, const char* text) {

    ImGuiWindow* window = ImGui::GetCurrentWindow ();

    const float wrapWidth = window->DC.TextWrapPos >= 0.0f ? ImGui::CalcWrapWidthForPos (window->DC.CursorPos, window->DC.TextWrapPos) : 0.0f;

    const ImVec2 textPosition (window->DC.CursorPos.x, window->DC.CursorPos.y + window->DC.CurrLineTextBaseOffset), textSize = ImGui::CalcTextSize (text, NULL, false, wrapWidth);

    //Calc text pos.
    ImRect rect (textPosition, textPosition + textSize);

    //For indent.
    ImGui::ItemSize (textSize + ImVec2 (0.f, 2.f), 0.0f);
    if (!ImGui::ItemAdd (rect, 0)) return;

    //Text render.               
    window->DrawList->AddText (rect.Min, color, text);
}

void UI::AdvancedRender::RenderOutputText (const char* prefix, const char* text) {

    ImGuiWindow* window = ImGui::GetCurrentWindow ();

    const float wrapWidth = window->DC.TextWrapPos >= 0.0f ? ImGui::CalcWrapWidthForPos (window->DC.CursorPos, window->DC.TextWrapPos) : 0.0f;

    const ImVec2 textPosition (window->DC.CursorPos.x, window->DC.CursorPos.y + window->DC.CurrLineTextBaseOffset), textSize = ImGui::CalcTextSize (text, NULL, false, wrapWidth);

    //Calc text pos.
    ImRect rect (textPosition, textPosition + textSize);

    //For indent.
    ImGui::ItemSize (textSize + ImVec2 (0.f, 5.f), 0.0f);
    if (!ImGui::ItemAdd (rect, 0)) return;

    //Prefix render.                
    window->DrawList->AddText (rect.Min, ImColor (200, 64, 64, 195), prefix);
    //Log render (auto-pos-calc).
    window->DrawList->AddText (UI::Fundamental::Fonts::SourceCodeProLight, 16.f, rect.Min + ImVec2 (ImGui::CalcTextSize (prefix, NULL, false, wrapWidth).x + 5.f, -1.f), ImColor (255, 255, 255, 255), text);
}

void UI::AdvancedRender::RenderContactInteractiveBoxCase (const char* child, const char* box, std::vector <UI::DataWrapper::InteractiveContact> interactiveContacts, ImVec2 size) {

    ImGui::BeginChild (child, size, true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

    {

        UI::AdvancedRender::RenderHeaderText (UI::Fundamental::Fonts::NunitoExtraBold, 18.f, ImColor (255, 255, 255, 195), box);
        ImGui::Dummy (ImVec2 (0.f, 2.5f));

        for (const auto& contact : interactiveContacts) {

            UI::AdvancedRender::RenderText (ImColor (255, 255, 255, UI::DataWrapper::Frames::GetLocalHashedObject (contact.m_text) ? 255 : 155), contact.m_text);

            //Make "copy" effect.
            UI::DataWrapper::Frames::SetLocalHashedObjectStatus (contact.m_text, !ImGui::IsItemClicked () && ImGui::IsItemHovered ());

            if (ImGui::IsItemClicked ()) ShellExecuteA (NULL, "open", contact.m_link, NULL, NULL, SW_SHOWNORMAL);

        }

    }

    ImGui::EndChild ();

}

void UI::AdvancedRender::RenderNews (UI::DataWrapper::News::DayNews info) {

    //Colors initialization.
    ImColor headerColor, dateColor, typeColor, categoryColor, logColor;
    ImVec4 child, border;

    switch (UI::DataWrapper::Frames::GetLocalHashedObject (info.m_headerInfo)) {

        case true:

            headerColor = ImColor (242, 242, 242, 255), dateColor = ImColor (168, 168, 168, 102), typeColor = ImColor (255, 255, 255, 155), logColor = ImColor (255, 255, 255, 204);
            child = ImVec4 (0.13f, 0.13f, 0.13f, 0.17f), border = ImVec4 (1.00f, 1.00f, 1.00f, 0.05f);

            break;

        case false:

            headerColor = ImColor (126, 126, 126, 255), dateColor = ImColor (53, 53, 53, 255), typeColor = ImColor (255, 255, 255, 102), logColor = ImColor (116, 116, 116, 255);
            child = ImVec4 (0.13f, 0.13f, 0.13f, 0.10f), border = ImVec4 (0.12f, 0.12f, 0.12f, 1.00f);

            break;

    }

    ImGui::PushStyleColor (ImGuiCol_ChildBg, child); //Set color for ImGui::BeginChild ();
    ImGui::PushStyleColor (ImGuiCol_Border, border); //Set outline color.

    ImGui::BeginChild (info.m_headerInfo, info.m_size, true);

    {

        //Header text.
        UI::AdvancedRender::RenderHeaderText (UI::Fundamental::Fonts::NunitoExtraBold, 18.f, headerColor, info.m_headerInfo);
        //News date.
        UI::AdvancedRender::RenderHeaderText (UI::Fundamental::Fonts::NunitoExtraBold, 16.f, logColor, info.m_date);

        for (const auto& news : info.m_news) {

            if (!news.second.empty ()) {

                ImGui::NewLine ();
                UI::AdvancedRender::RenderText (typeColor, UI::DataWrapper::News::TypeToText (static_cast <UI::DataWrapper::News::Type> (news.first)));

                for (const auto& category : news.second) {

                    if (!category.second.empty ()) {

                        UI::AdvancedRender::RenderText (typeColor, UI::DataWrapper::News::CategoryToText (static_cast <UI::DataWrapper::News::Category> (category.first)));

                        for (const auto& text : category.second) {

                            UI::AdvancedRender::RenderText (logColor, std::string ("- ").append (text).append ("\n").c_str ());

                        }

                    }

                }
            }

        }

    }

    ImGui::EndChild ();

    UI::DataWrapper::Frames::SetLocalHashedObjectStatus (info.m_headerInfo, ImGui::IsItemHovered (ImGuiHoveredFlags_RectOnly));

    ImGui::PopStyleColor (2); //Close colors.
}

// ---- END WRAPPERS FOR ADVANCED RENDER ----