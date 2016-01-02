#ifndef TERMINAL_MEDIA_PLUGIN_IREGISTRAR_HPP_
#define TERMINAL_MEDIA_PLUGIN_IREGISTRAR_HPP_

#include <terminal/media/plugin/Types.hpp>
#include <terminal/media/plugin/IPlugin.hpp>

namespace terminal {
  namespace media {
    namespace plugin {
      class IRegistrar {
      public:
        virtual ~IRegistrar() = default;

        virtual IPlugin *registerPlugin(struct PluginInfo const *info) = 0;

      private:
      };
    }
  }
}

#endif
