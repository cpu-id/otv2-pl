#pragma once

 /**                

    ._______________________________________________________.
    .                 O T C - L O A D E R                   .
    ._______________________________________________________.
    !                                                       !
    | Credits:                                              |
    |                                                       |
    | |=> 0x000cb <-> Lead dev # Design help.               |
    | |=> Sove    <-> Lead design.                          |
    | |=> enQ     <-> Design.                               |
    | |=> Keaton  <-> ImGui helper.                         |
    |_______________________________________________________|
    !                                                       !
    | Special thanks to testers:                            |
    |                                                       |
    | |=> Racoon   <-> Lead tester.                         |
    | |=> HoShiMin <-> Tester # Design help.                |
    !                                                       !
    ._______________________________________________________.
    .                  (c) CpuId. 2020.                     .
    ._______________________________________________________.

 **/

//Allow math operations with ImVectors.
#define IMGUI_DEFINE_MATH_OPERATORS

//Enum -> enum class.
#pragma warning (disable : 26812)
//D3x issue.
#pragma warning (disable : 26495)
//LPWSTR -> WORD.
#pragma warning (disable : 4302)

//Common imports, global helpers, etc.
#include "../../../Vendor.hpp"

//Callback status.
#include "../callback/CallbackManager.hpp"

//Language and configuration.
#include "../accessors/LanguageAccessor.hpp"
#include "../accessors/ConfigurationAccessor.hpp"

//Discord RPC.
#include "../util/DiscordRPC.hpp"

//Renderer.
#include "../../../../thirdparty/source/gui/imgui/ImGui.hpp"
#include "../../../../thirdparty/source/gui/imgui/ImGuiImplDx9.hpp"
#include "../../../../thirdparty/source/gui/imgui/ImGuiImplWin32.hpp"
#include "../../../../thirdparty/source/gui/imgui/ImGuiInternal.hpp"

//DirectX.
#include <d3dx9tex.h>

//User-Interface.
namespace UI {

    //Control center.
    namespace Fundamental {

        //Buffers classification for storage.
        //
        // SYS_  -> Storage::SystemBuffers | Support all getters/setters operations.
        // TEMP_ -> Storage::TempBuffers   | Support only getters operations.
        // TEXT_ -> Storage::TextBuffers   | Almost all buffers support getters/setters operations.
        //
        //FIXME: Maybe need remove "Buffers" suffix from Storage caused by override.
        enum Buffers {

            //Current page for frame. (GETTER/SETTER -> UI::DataWrapper::Frames)
            SYS_FRAME_PAGES,
            //Hovered item status.    (GETTER/SETTER -> UI::DataWrapper::Frames)
            SYS_FRAME_HOVERED,
            //Configuration values.   (GETTER/SETTER -> UI::DataWrapper::Configuration) 
            SYS_CONF_LIST,

            //News list for first page.                     (GETTER -> UI::DataWrapper::News)
            TEXT_NEWS_LIST,

            //List of modules from load, with oep separator. (GETTER -> UI::DataWrapper::Load)
            TEMP_LOAD_ADDONS,
            //Load status at simply info.                    (GETTER/SETTER -> UI::DataWrapper::Load/UI::DataWrapper::Language)
            TEMP_LOAD_INFO,
            //Load status in detail info.                    (GETTER/SETTER -> UI::DataWrapper::Load/UI::DataWrapper::Language)
            TEMP_LOAD_DEBUG,

        };

        //Fonts installer: UI::Fundametal::Wakeup. (All fonts in folder: "dependency/fonts" at unsigned char array view)
        namespace Fonts {

            //NUNITO-FAMILY.

            //Used for extensions detail info. (Size: 18.f)
            extern ImFont* NunitoLight;
            //Used for logo name (Size: 18.f) / Child boxes format. (Size: 22.f)
            extern ImFont* NunitoExtraBold;
            //Used for tabs name (Size: 18.f/Desc: Icon | Tab name) / Issues format in the [readme] console. (Size: 16.f)
            extern ImFont* NunitoBold;
            //Used for build name by default. (Size: 16.f)
            extern ImFont* NunitoSemiBold;

            //SOURCE-CODE-PRO-FAMILY.

            //Used for output in console by default. (Size: 16.f)
            extern ImFont* SourceCodeProLight;

            //STUFF.

            //
            // Used for render tabs icons.
            //
            // Char -> Icon.
            //
            // '0' -> Newspaper.
            // '1' -> Console.
            // '2' -> Adv.Console.
            // '3' -> Cogwheel.
            //
            extern ImFont* SysIcons;

        };

        //DirectX.
        namespace D3X {

            //Main device for i/o.
            extern LPDIRECT3DDEVICE9 Device;
            //Logo.
            extern LPDIRECT3DTEXTURE9 LogoTexture;

        };

        //Updates, etc.
        namespace VersionControl {

            //Major - Global version.
            //Local - Local updates version.
            extern int BuildMajorVer, BuildLocalVer;

            //Returns true if: The version is different / An error occurred. (See the function declaration for details)
            extern bool IsVersionDifference ();

        };

        //Used for hide/show menu when user press [INSERT] key.
        extern bool IsMenuShowing;
    
        //Main functions for the control UI process.
        extern void Wakeup (HWND hwnd), Routine ();

        //Heartbeat / Render the UI.
        extern void RenderFrameBuffer ();

    };

    //Wrapper for storage / Just utils.
    namespace DataWrapper {

        struct InteractiveContact {

            //The text that will be rendered in the menu.
            const char* m_text;
            //The link to be opened. (If user click on m_text)
            const char* m_link;
                
        };

        struct PrefixedText {

           //Caller/Status. (Example: [LD])
           const char* m_prefix;
           //Message after prefix. (New line messages format to prefix [x] position)
           std::string m_message;

        };

        //Wrap from: 
        //
        // - Page:    DummyMemory->Storage->SystemBuffers->Frames->Pages.
        // - Hovered: DummyMemory->Storage->SystemBuffers->Frames->Hovers.
        //
        //Use static_cast to convert in enum.
        namespace Frames {

            //Main content.
            enum Pages { NEWS, LOAD, EXTENSIONS, SETTINGS };
            //Sub-pages of the LOAD page.
            enum LoadPages { README, ADDONS, SEGMENT };

            extern int  
                        //Get current content page.
                        GetCurrentPage (), 
                        //Get sub-load content page.
                        GetCurrentLoadPage ();

            extern void 
                        //Change current content page. (For increment/sub use IncCurrentPage)
                        SetCurrentPage (Pages page), 
                        //Change current sub-load content page. (For increment/sub use IncCurrentLoadPage)
                        SetCurrentLoadPage (LoadPages page), 
                        //Set/Emplace object to status buffer, as object name you can use child name. (Note: isEmplace - sys value. Please don't change/use it)
                        SetLocalHashedObjectStatus (std::string object, bool value, bool isEmplace = false),
                        
                        //Increment/sub content pages.
                        //
                        //Reversed: true -> [--] / false (by default) -> [++].
                        IncCurrentPage (bool reversed = false),
                        IncCurrentLoadPage (bool reversed = false);

            extern bool
                        //Used for get object status like hovered/pressed. 
                        GetLocalHashedObject (std::string object),
                       
                        CmpCurrentPage (Pages target),
                        CmpCurrentLoadPage (LoadPages page);

            extern bool&
                        //Dependency by things like imgui checkbox's, etc.
                        GetLocalHashedReferencedObject (std::string object);

        };

        //Wrap from: DummyMemory->Storage->TextBuffers->News.
        //
        //TODO: Json wrapper for news & download server.
        namespace News {

            //News section.
            enum Type { OTC, LOADER };

            //News sub-section. 
            //
            //FIXME: The category "REMOVED" is useless in 90% of cases. Need to be removed in the next updates.
            enum Category { ADDED, REWORKED, REMOVED, IMPROVED };

            //Make render more easier.
            struct DayNews {

                //Topic.
                const char* m_headerInfo;

                //Publish/update date.
                //
                //WONTFIX: You can use time (0), but you have to rewrite the whole architecture.
                const char* m_date;

                // MAP VIEW:
                // 
                // Type [OTC / LOADER]
                //                     | ->
                //                          Category [ADDED / REWORKED / REMOVED / IMPROVED]
                //                                                                           | ->
                //                                                                                List with news.
                std::map <Type, std::map <Category, std::vector <const char*>>> m_news;

                //Size of tab.
                //
                //FIXME: Need to change ImVec (X, Y) to int (only Y). (The X position does not change, it may be needed if someone wants to change the menu, but it is useless in other cases)
                ImVec2 m_size = ImVec2 (321, 150);

            };

            /**
             *
             * @point - Parse enum type to text.
             * @args  - Type: News section type. (Range: 0 -> 1 | OTC -> LOADER)
             *
             * @author - 0x000cb. / 24.08.20
             *
             **/

            extern const char* TypeToText (Type type);

            /**
             *
             * @point - Parse enum type to text.
             * @args  - Category: News category type. (Range: 0 -> 3 | ADDED -> IMPROVED)
             *
             * @author - 0x000cb. / 24.08.20
             *
             **/

            extern const char* CategoryToText (Category category);

            /**
             *
             * @point - Wrapper for the news buffer in storage.
             *
             * @author - 0x000cb. / 05.08.20
             *
             **/

            extern std::vector <DayNews> GetInfoAtProvider ();

        };

        //Wrap from: DummyMemory->Storage->TempBuffers->Load.
        namespace Load {

            //OEP - Original entry point. More about: https://www.aldeid.com/wiki/OEP-Original-Entry-Point.
            enum OEPType { BEFORE, AFTER };

            /**
             *
             * @point - Simplify getter for buf/Wrapper for output buffer.
             *
             * @author - 0x000cb. / 15.09.20
             *
             **/

            extern UI::Fundamental::Buffers GetCurrentLoadBufferOutputPage ();

            /**
             *
             * @point - Simplify setter for buf/Wrapper for output buffer.
             * @args  - Buffers: TEMP_LOAD_INFO, TEMP_LOAD_DEBUG.
             *
             * @author - 0x000cb. / 15.09.20
             *
             **/

            extern void SetCurrentLoadBufferOutputPage (UI::Fundamental::Buffers buffers);

            /**
             *
             * @point - Put message to current output buffer. (!Note: You can change output buffer in settings)
             * @args  - Prefix: Prefix for message. Path: Path to message in current output buffer.
             *
             * @author - 0x000cb. / 10.09.20
             *
             **/

            extern void PutMessageToLdOutput (const char* prefix, std::string path);

            /**
             *
             * @point - Get all path's to modules from ui. (!Note: Referenced for simplify edit)
             * @args  - Provider: BEFORE, AFTER.
             *
             * @author - 0x000cb. / 24.08.20
             *
             **/

             extern std::vector <std::string>& GetFilePathToAddon (OEPType provider);

             /**
              *
              * @point - Render all messages to ui from output buffer.
              * @args  - Buffer: TEMP_LOAD_INFO, TEMP_LOAD_DEBUG. (!Language manager not supported!)
              *
              * @author - 0x000cb. / 10.09.20
              *
              **/

             extern Concurrency::concurrent_vector <UI::DataWrapper::PrefixedText> GetMessagesFromLdOutput (UI::Fundamental::Buffers buffer);

        };

        namespace Configuration {

            /**
             *
             * @point - Logic processor for user props & setup buttons status. (!Note: Supported only user-side properties)
             *
             * @author - 0x000cb. / 20.09.20
             *
             **/

            void SetupPropertiesHashedObjects ();

        }

        //Wrap from: 
        //
        // Message - DummyMemory->Storage->TextBuffers->Messages.
        // Region  - DummyMemory->Storage->SystemBuffers->SelectedRegion;
        namespace Language {

            /**
             *
             * @point - Simplify get message from storage for current lang.
             * @args  - Path: Path to message in map. (!Note: Current region auto-add to path)
             *
             * @author - 0x000cb. / 11.09.20
             *
             **/

            extern const char* TranslateMessage (std::string path);

            /**
             *
             * @point - Simplify get current region / Just wrapper for storage.
             *
             * @author - 0x000cb. / 11.09.20
             *
             **/

            extern LanguageProvider::Region GetSelectedRegion ();

            /**
             *
             * @point - Compare selected region with argument.
             * @args  - Target: Region to compare.
             *
             * @author - 0x000cb. / 11.09.20
             *
             **/

            extern bool CmpSelectedRegion (LanguageProvider::Region target);


        };

    };

    //Just a storage for objects so not need to create a thousand variables.
    namespace Storage {

        //Buffers for the temp render per frame.
        namespace TempBuffers {

           //Buffers for the load manager (!Note: Clean-up after load).
           namespace Load {

              //Load console log. [In thread safe vector]
              extern Concurrency::concurrent_vector <UI::DataWrapper::PrefixedText> Info, Debug;
              //Modules path.
              extern std::map <UI::DataWrapper::Load::OEPType, std::vector <std::string>> Addons;

           };

        };

        //Buffers for the messages/output.
        namespace TextBuffers {

            //Language-dependency oriented news.
            extern std::map <LanguageProvider::Region, std::vector <UI::DataWrapper::News::DayNews>> NewsData;

        };

        //Buffers for the important values.
        namespace SystemBuffers {

            //Links.
            namespace Frames {

                //Selected tab.
                extern std::map <std::string, int> Pages;
                //Objects status like hovered/pressed/etc. (ImGui wrappers return only next object like in this video: https://www.youtube.com/watch?v=8_BEk3coSwg)
                extern std::map <std::string, bool> LocalObjectsStatus;

            };

            //Global selected region.
            extern LanguageProvider::Region SelectedRegion;

        }

        /**
         *
         * @point - Flush temp buffers after X action.
         * 
         * @author - 0x000cb. \ 11.09.20
         *
         **/

        extern void FlushCandidateTempBuffers ();

    };

    //Advanced wrappers for ImGui render side.
    namespace AdvancedRender {

        /**
         *
         * There will be no documentation because ->
         *
         * 1. These functions are just an addition to the ImGUI API.
         * 2. These functions written by Keaton, and even God doesn't know how it can work.
         *
         **/

        extern bool RenderTabEx (const char* icon, const char* label, const bool active, const ImVec2& argSize, ImGuiButtonFlags flags), RenderPageEx (const char* label, const ImVec2& argSize, ImGuiButtonFlags flags, const int dir), RenderBoxEx (const char* label, const bool active, const ImVec2& argSize, ImGuiButtonFlags flags);

        //Wrappers for Ex.
        extern bool RenderTab (const char* icon, const char* label, const bool active, const ImVec2& argSize), RenderPage (const char* label, const ImVec2& argSize, const int dir), RenderBox (const char* label, const bool active, const ImVec2& argSize);

        /**
         *
         *   @point     - No need to use ImGui::PushFont () or ImGui::PopFont ().
         *   @example   - UI::AdvancedRender::RenderHeaderText (UI::Fundamental::Fonts::NunitoBold, 18.f, ImColor (255, 255, 255, 255), "Header text");
         *   @args      - Font: Pointer to font (See: UI#Fundamental#Fonts). Font size: Just font size (!Note: Use %2 values for font size). Color: Text color. Text: Text to render.
         *
         *   @author      - Keaton  | 04 / 08 / 2020 - 4:16AM.
         *   @refactoring - 0x000cb | 10 / 08 / 2020 - 3:53AM.
         *
         **/

        extern void RenderHeaderText (const ImFont* font, float fontSize, ImColor color, const char* text);
        
        /**
         *
         * @point   - Created for render log text with custom color in rgb and imcolor.
         * @example - UI::AdvancedRender::RenderText (ImColor (255, 255, 255, 255), "Test");
         * @args    - Color: Text color. Text: Text to render.
         *
         * @author      - Keaton  | 05 / 08 / 2020 - 2:19PM.
         * @refactoring - 0x000cb | 10 / 08 / 2020 - 4:22AM.
         *
         **/

        extern void RenderText (ImColor color, const char* text);

        /**
         *
         * @point   - Simple & advanced render news tabs.
         * @example - UI::AdvancedRender::RenderNews (UI::DataWrapper::News::GetInfoAtProvider ().at (0), true);
         * @args    - Info: Filled news struct (!Note: Use DataWrapper::News for get filled news).
         *
         * @author      - Keaton  | 05 / 08 / 2020 - 2:37PM.
         * @refactoring - 0x000cb | 10 / 08 / 2020 - 4:49AM.
         *
         **/

        extern void RenderNews (UI::DataWrapper::News::DayNews info);

        /**
         *
         * @point   - Simple text render with own prefixes. Most used in extensions/load tab.
         * @example - UI::AdvancedRender::RenderOutputText ("[L33t]", "Test");
         * @args    - Prefix: Prefix to render (!Note: Prefix have red color & text splited by prefix). Text: Text to the render.
         *
         * @author      - Keaton  | 05 / 08 / 2020 - 1:05PM.
         * @refactoring - 0x000cb | 10 / 08 / 2020 - 5:02AM.
         *
         **/


        extern void RenderOutputText (const char* prefix, const char* text);

        /**
         *
         * @point   - Create сonvenient rendering of contacts in an additional box.
         * @example - UI::AdvancedRender::RenderContactInteractiveBoxCase ("##beatbox", "Donate", { UI::DataWrapper::InteractiveContact { "Pure man from somalia", "rickrolled.com" } }, ImVec2 (X, Y));  
         * @args    - Child: ImGui child ID. Box: Box header. InteractiveContacts: Vector with filled contacts to render. Size: Box size.
         *
         * @author - 0x000cb | 18 / 08 / 2020 - 05:08AM.
         *
         **/

        extern void RenderContactInteractiveBoxCase (const char* child, const char* box, std::vector <UI::DataWrapper::InteractiveContact> interactiveContacts, ImVec2 size);

    };

};