#pragma once

#include "../../../Vendor.hpp"

namespace DiscordRPC {

    //Global discord-rpc integration manager pointer.
    extern DiscordRichPresence DiscordPresence;

    /**
     *
     * @point - Initialize discord rpc & setup default rpc configuration.
     * @args  - DefaultState: Default rpc header text. LogoName: Server-side logo name/Path to logo. LogoText: Text at big logo.
     *
     * @author - 0x000cb. / 14.10.20
     *
     **/

    extern void SetupDefaultRPC (const char* defaultState, const char* logoName, const char* logoText);

    /**
     * 
     * @point - Fast & simplify set current discord state.
     * @args  - State: RPC state name.
     *
     * @author - 0x00cb. / 14.10.20
     *
     */

    extern void SetRpcState (std::string state);

}