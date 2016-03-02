#ifndef TERMINAL_MEDIA_PLUGIN_TYPES_HPP_
#define TERMINAL_MEDIA_PLUGIN_TYPES_HPP_

#include <cstdint>
#include <array>

namespace terminal {
  namespace media {
    namespace api {
      typedef std::string string;
      typedef std::array<uint8_t, 16> uuid_type;

      struct Version {
        uint16_t major_;
        uint16_t minor_;
        uint16_t release_;
        uint16_t build_;

        Version(uint16_t major, uint16_t minor, uint16_t release, uint16_t build) :
          major_(major),
          minor_(minor),
          release_(release),
          build_(build)
        {
        }

        Version(uint16_t major, uint16_t minor, uint16_t release) :
          Version(major, minor, release, 0)
        {
        }

        Version(uint16_t major, uint16_t minor) :
          Version(major, minor, 0, 0)
        {
        }
      };

      enum class ExtensionType {
        EXTENSION_LIBRARY_MANAGER = (1 << 0),
        EXTENSION_AUDIO_INTERFACE = (1 << 1),
      };

      struct ExtensionInfo {
        Version version;
        ExtensionType type;
        uuid_type uuid;
        string name;
      };

      struct PluginInfo {
        Version version;
        uuid_type uuid;
        string name;
      };
    }
  }
}

#endif
