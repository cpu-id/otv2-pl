#pragma once

//WinAPI stuff.
#include <Windows.h>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <Psapi.h>
#include <dinput.h>
#include <concurrent_vector.h>
#include <libloaderapi.h>
#include <tchar.h>
#include <d3d9.h>
#include <time.h>

//Legacy utils.
#include "primal/util/CommonUtil.hpp"
#include "primal/util/PanicUtil.hpp"
#include "primal/util/stuff/Singleton.hpp"
#include "primal/util/stuff/RuntimeDefinitions.hpp"

//Hooks reflection.
#include "../thirdparty/source/hooks/Detours.hpp"
#pragma comment (lib, "../../thirdparty/assembled/hooks/detours.lib")

//Render.
#pragma comment (lib, "../../thirdparty/assembled/gui/d3dx9.lib")

//RPC.
#include "../thirdparty/source/discord/DiscordRPC.hpp"
#pragma comment (lib, "../../thirdparty/assembled/discord/discord-rpc.lib")