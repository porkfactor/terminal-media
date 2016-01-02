#ifndef PLAYER_SYSTEM_PLUGINREGISTRAR_HPP_
#define PLAYER_SYSTEM_PLUGINREGISTRAR_HPP_

#include <terminal/media/plugin/IRegistrar.hpp>

namespace terminal {
  namespace media {
    class PluginRegistrar : public plugin::IRegistrar {
    public:
      PluginRegistrar();

      plugin::IPlugin *registerPlugin(struct plugin::PluginInfo const *);

    private:
    };
  }
}

#endif
