#pragma once

#include "../../../Vendor.hpp"

namespace LanguageProvider {

    //New language can be here.
    enum Region { EN, RU };

    //Place new buffers type here.
    enum BufferType { UI, PRIMAL };

    //Place new buffers here.
    namespace Buffers {

        extern std::map <std::string, const char*> UIMessages;
        extern std::map <std::string, const char*> PrimalMessages;

    };

    /**
     *
     * @point - Get message from buffer with language-dependency.
     * @args  - Region: Region to take the message. BufferType: UI, PRIMAL_INFO, PRIMAL_DEBUG. Path: Path to message in buffer.
     *
     * @author - 0x000cb. / 14.09.20
     *
     **/

    extern const char* GetRegionalMessageFromBuffer (Region region, BufferType buffer, std::string path);

    /**
     *
     * @point - Translate enum type to text. (Needed for get message from buffer with language-dependency)
     *
     * @author - 0x000cb. / 11.09.20
     *
     **/

    extern const char* RegionToText (Region region);

    /**
     *
     * @args - Region: Region to take the message. BufferType: UI, PRIMAL_INFO, PRIMAL_DEBUG, Path: Path to message in buffer. Format: String's to replace format.
     *
     * @author - 0x000cb. / 12.10.20
     */

    extern const char* GetFormattedMessageFromRegionalBuffer (Region region, BufferType buffer, std::string path, const char* format...);

};