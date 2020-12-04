#pragma once

#include "../../../Vendor.hpp"

namespace ConfigurationProvider {

    //Common defines for simplify get path to registry data.
    #define CPUID_REG_SYSTEM_DATA_PATH "Software\\CpuId\\OTC\\Loader\\System"
    #define CPUID_REG_CONFIGURATION_DATA_PATH "Software\\CpuId\\OTC\\Loader\\Data"

    //Windows registry. We used it like alternative for configuration files.
    namespace Registry {

        //Links to registry data.
        extern HKEY RegSystemData, RegConfigurationData;

    };

    //Properties classification.
    //
    //DEFAULT - User-side configuration space.
    //SYSTEM - Loader-side configuration space.
    enum Properties {

        //Use discord rich presence?
        DEFAULT_USER_DISCORD_RPC,
        //Selected language type.
        DEFAULT_USER_SELECTED_LANG,
        //Enable debug load mode?
        DEFAULT_DEV_DEBUG_LOAD,

        //Current build version as major.
        SYSTEM_CURRENT_VER_MAJOR,
        //Current build version as local.
        SYSTEM_CURRENT_VER_LOCAL,

    };

    /**
     *
     * @point - Get property value from registry (!Note: Supported only user-side properties).
     * @args  - Prop: Property type. (!Note: For cast use static_cast)
     *
     * @author - 0x000cb. / 11.09.20
     *
     **/

    extern int GetPropertiesValue (Properties prop);

    /**
     *
     * @point - Set property value in registry (!Note: Supported only user-side properties).
     * @args  - Prop: Property type. Value: New value. (4 bytes)
     *
     * @author - 0x000cb. / 11.09.20
     *
     **/

    extern void SetPropertiesValue (Properties prop, int value);

    /**
     *
     * @point - Add user properties as default to registry.
     *
     * @author - 0x000cb. / 20.09.20
     *
     **/

    extern void InitializeUserSideProperties ();

    /**
     *
     * @point - Add system properties as default to registry. (!Note: Created only for internal usage)
     *
     * @author - 0x000cb. / 21.09.20
     *
     **/

    extern void InitializeSystemSideProperties ();

    /**
     *
     * @point - Logic processor for user props & setup buttons status. (!Note: Supported only user-side properties)
     *
     * @author - 0x000cb. / 20.09.20
     *
     **/

    extern void SetupPropertiesHashedObjects ();

    /**
     *
     * @point - Parse enum type to text. (!Note: Supported only user-side properties)
     * @args  - Prop: Properties range [0 -> 1 | USER_DISCORD_RPC -> DEV_DEBUG_LOAD] (!Note: Very flexable thing. May changed after daily update)
     *
     * @author - 0x000cb. / 20.09.20
     *
     **/

    extern std::string PropertiesToText (Properties prop);

    /**
     *
     * @point - Get current prop value from registry and set differentiate value. (!Note: Supported only user-side properties | Showcase: set [!value] to registry)
     * @args  - Prop: Target user properties.
     *
     * @author - 0x000cb. / 20.09.20
     *
     **/

    extern void SetPropertiesDifferencialValue (Properties prop);

    /**
     *
     * @point - Get all user properties for setup/initialize props in map/registry.
     *
     * @author - 0x000cb. / 20.09.20
     *
     **/

    extern std::vector <Properties> GetUserPropertiesList ();

    /**
     *
     * @point - The cold start concept is needed to reset all loader settings to default. Mostly used if the current build version is different from the saved one. (!Note: DON'T USE IT MANUALLY)
     * @args  - IsWipe: Delete previos keys with all data inside.
     *
     * @author - 0x000cb. / 21.09.20
     *
     **/

    extern void DoColdPropertiesWakeup (bool isWipe);

};