#include "ConfigurationAccessor.hpp"

HKEY ConfigurationProvider::Registry::RegSystemData = NULL;
HKEY ConfigurationProvider::Registry::RegConfigurationData = NULL;

int ConfigurationProvider::GetPropertiesValue (ConfigurationProvider::Properties prop) {

    LPDWORD buffer = NULL;
    //Result.
    DWORD output = NULL;

    RegGetValueA (ConfigurationProvider::Registry::RegConfigurationData, NULL, ConfigurationProvider::PropertiesToText (prop).c_str (), RRF_RT_REG_BINARY, NULL, buffer, &output);

    return output;
}

void ConfigurationProvider::SetPropertiesDifferencialValue (ConfigurationProvider::Properties prop) {
    ConfigurationProvider::SetPropertiesValue (prop, !ConfigurationProvider::GetPropertiesValue (prop));
}

void ConfigurationProvider::SetPropertiesValue (ConfigurationProvider::Properties prop, int value) {
    RegSetKeyValueA (ConfigurationProvider::Registry::RegConfigurationData, NULL, ConfigurationProvider::PropertiesToText (prop).c_str (), REG_BINARY, reinterpret_cast <LPCVOID> (&value), value);
}

void ConfigurationProvider::InitializeUserSideProperties () {

    for (const auto& prop : ConfigurationProvider::GetUserPropertiesList ()) {
        ConfigurationProvider::SetPropertiesValue (prop, false);
    }

}

void ConfigurationProvider::InitializeSystemSideProperties () {

    //"Hidden enums".

    auto PropertiesToText = [](ConfigurationProvider::Properties props) {

        switch (props) {

            default:
            case ConfigurationProvider::Properties::SYSTEM_CURRENT_VER_MAJOR: return "ver.major";
            case ConfigurationProvider::Properties::SYSTEM_CURRENT_VER_LOCAL: return "ver.local";

        };

    };

    std::map <ConfigurationProvider::Properties, int> properties = {

            { ConfigurationProvider::Properties::SYSTEM_CURRENT_VER_MAJOR, 1 },
            { ConfigurationProvider::Properties::SYSTEM_CURRENT_VER_LOCAL, 0 },

    };

    for (const auto& prop : properties) {
        RegSetKeyValueA (ConfigurationProvider::Registry::RegSystemData, NULL, PropertiesToText (prop.first), REG_BINARY, reinterpret_cast <LPCVOID> (&prop.second), prop.second);
    }

}

std::string ConfigurationProvider::PropertiesToText (ConfigurationProvider::Properties prop) {

    switch (prop) {

        default:
        case ConfigurationProvider::Properties::DEFAULT_USER_DISCORD_RPC:   return "us.disrpc";
        case ConfigurationProvider::Properties::DEFAULT_USER_SELECTED_LANG: return "us.lang";
        case ConfigurationProvider::Properties::DEFAULT_DEV_DEBUG_LOAD:     return "dv.dbgload";

    }

}

std::vector <ConfigurationProvider::Properties> ConfigurationProvider::GetUserPropertiesList () {
    return { ConfigurationProvider::Properties::DEFAULT_USER_DISCORD_RPC, ConfigurationProvider::Properties::DEFAULT_USER_SELECTED_LANG, ConfigurationProvider::Properties::DEFAULT_DEV_DEBUG_LOAD };
}

void ConfigurationProvider::DoColdPropertiesWakeup (bool isWipe) {

    //Is need to remove old keys?
    if (isWipe) {

        //Remove all old keys for reset.
        RegDeleteKeyA (HKEY_CURRENT_USER, CPUID_REG_SYSTEM_DATA_PATH);
        RegDeleteKeyA (HKEY_CURRENT_USER, CPUID_REG_CONFIGURATION_DATA_PATH);

    }

    //Create new registry data.
    if (RegCreateKeyA (HKEY_CURRENT_USER, CPUID_REG_SYSTEM_DATA_PATH, &ConfigurationProvider::Registry::RegSystemData) != ERROR_SUCCESS || RegCreateKeyA (HKEY_CURRENT_USER, CPUID_REG_CONFIGURATION_DATA_PATH, &ConfigurationProvider::Registry::RegConfigurationData)) {
        //If we can't create keys -> Shutdown.
        Primal::PanicUtil::Release ("ConfigurationProvider::DoColdPropertiesWakeup->RegCreateKey", "Can't create configuration keys in system registry. Check user-access rights.");
    }

    //Setup new default data.
    ConfigurationProvider::InitializeSystemSideProperties ();
    ConfigurationProvider::InitializeUserSideProperties ();

}