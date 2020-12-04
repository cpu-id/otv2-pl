#include "DiscordRPC.hpp"

DiscordRichPresence DiscordRPC::DiscordPresence = { };

void DiscordRPC::SetupDefaultRPC (const char* defaultState, const char* logoName, const char* logoText) {

    //Connect to cloud app configuration.
    Discord_Initialize (DISCORD_APPLICATION_ID, nullptr, 1, NULL);

    memset (&DiscordRPC::DiscordPresence, 0, sizeof (DiscordRPC::DiscordPresence));

    //Setup rich presence.
    DiscordRPC::DiscordPresence.state = defaultState;
    DiscordRPC::DiscordPresence.largeImageKey = logoName;
    DiscordRPC::DiscordPresence.largeImageText = logoText;

    //Update rich presence.
    Discord_UpdatePresence (&DiscordRPC::DiscordPresence);

}

void DiscordRPC::SetRpcState (std::string state) {

    DiscordRPC::DiscordPresence.state = state.c_str ();

    Discord_UpdatePresence (&DiscordRPC::DiscordPresence);

}