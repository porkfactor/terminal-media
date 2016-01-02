#ifndef TERMINAL_MEDIA_PLUGIN_TYPES_HPP_
#define TERMINAL_MEDIA_PLUGIN_TYPES_HPP_

#include <cstdint>

namespace terminal {
  namespace media {
    namespace plugin {
      struct PluginVersion {
        uint16_t major_;
        uint16_t minor_;
        uint16_t release_;
        uint16_t build_;

        PluginVersion(uint16_t major, uint16_t minor, uint16_t release, uint16_t build) :
          major_(major),
          minor_(minor),
          release_(release),
          build_(build)
        {
        }

        PluginVersion(uint16_t major, uint16_t minor, uint16_t release) :
          PluginVersion(major, minor, release, 0)
        {
        }

        PluginVersion(uint16_t major, uint16_t minor) :
          PluginVersion(major, minor, 0, 0)
        {
        }
      };

      struct PluginUUID {
        uint8_t uuid_[16];
      };

      enum class PluginType {
        PLUGIN_LIBRARY_MANAGER = (1 << 0),
        PLUGIN_AUDIO_INTERFACE = (1 << 1),
      };

      struct PluginInfo {
        PluginVersion version;
        PluginType type;
      };
    }
  }
}

#endif
