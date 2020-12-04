cmake_minimum_required(VERSION 3.16.5)

#From scratch to sky.
project(otv2-pl)
set(CMAKE_CXX_STANDARD 14)

#Loader.
set(

        PRIMAL_LOADER_SOURCE

        #Segment data.
        src/primal/segment/internal/SegmentNativeData.cpp

        #Runtime handler's.
        src/primal/runtime/reconstructor/Reconstructor.hpp
        src/primal/runtime/reconstructor/reconstructors/IATReconstructor.cpp
        src/primal/runtime/reconstructor/reconstructors/RelocReconstructor.cpp
        src/primal/runtime/RuntimeEngine.cpp

        #Utils.
        src/primal/util/stuff/RuntimeDefinitions.cpp
        src/primal/util/CommonUtil.cpp
        src/primal/util/PanicUtil.cpp

)

#Segment data.
set(
        ONE_SEGMENT_SOURCE

        #Segment data.
        src/segment/data/sections/IAT.cpp
        src/segment/data/sections/Reloc.cpp
        src/segment/data/OneSegment.cpp

        #Loader data.
        src/segment/loader/accessors/ConfigurationAccessor.cpp
        src/segment/loader/accessors/LanguageAccessor.cpp
        src/segment/loader/ui/UIRenderer.cpp
        src/segment/loader/ui/UIBridge.cpp
        src/segment/loader/callback/CallbackManager.cpp
        src/segment/loader/bootstrap/BootstrapTaskController.cpp
        src/segment/loader/bootstrap/Bootstrap.cpp

        #Framework routine.
        src/segment/internal/framework/sdk/game/memory/VirtualReflectionHandler.cpp
        src/segment/internal/framework/OneEngine.cpp

        #Utils.
        src/segment/loader/util/DiscordRPC.cpp

)

#Libs.
set(
        THIRD_PARTY_SOURCE

        #UI.
        thirdparty/source/gui/imgui/ImGui.cpp
        thirdparty/source/gui/imgui/ImGuiDraw.cpp
        thirdparty/source/gui/imgui/ImGuiImplDx9.cpp
        thirdparty/source/gui/imgui/ImGuiImplWin32.cpp
        thirdparty/source/gui/imgui/ImGuiWidgets.cpp
)

#RU language dependency...
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

#D3X9 includes.
include_directories(C:/DxSDK/Include)

#Build.
add_library(otv2-pl SHARED ${PRIMAL_LOADER_SOURCE} ${THIRD_PARTY_SOURCE} ${ONE_SEGMENT_SOURCE})