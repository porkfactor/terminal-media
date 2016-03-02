#ifndef PLAYER_SYSTEM_PLUGINREGISTRAR_HPP_
#define PLAYER_SYSTEM_PLUGINREGISTRAR_HPP_

#include <terminal/media/api/IRegistrar.hpp>
#include <terminal/media/pimpl.hpp>

namespace terminal {
  namespace media {
    class PluginRegistrar : public api::IRegistrar {
    public:
      PluginRegistrar();
      virtual ~PluginRegistrar();

      void registerPlugin(api::IPlugin *plugin);
      void registerExtension(api::IExtensionFactory *extension);

      api::IExtension *createExtension(api::ExtensionType type, api::string const &) const override;
      api::IExtension *createExtension(api::uuid_type const &uuid) const override;

    private:
      struct impl;
      pimpl<impl> pimpl_;
    };
  }
}

#endif
