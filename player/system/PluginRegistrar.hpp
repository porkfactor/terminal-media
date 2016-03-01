#ifndef PLAYER_SYSTEM_PLUGINREGISTRAR_HPP_
#define PLAYER_SYSTEM_PLUGINREGISTRAR_HPP_

#include <terminal/media/api/IRegistrar.hpp>

namespace terminal {
  namespace media {
    namespace api {
      class IPlugin;
      class IExtensionFactory;
    }

    class PluginRegistrar : public api::IRegistrar {
    public:
      PluginRegistrar();
      virtual ~PluginRegistrar();

      void registerPlugin(api::IPlugin *plugin);
      void registerExtension(api::IExtensionFactory *extension);

    private:
    };
  }
}

#endif
