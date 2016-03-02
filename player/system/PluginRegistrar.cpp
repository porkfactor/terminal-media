#include <terminal/media/api/IPlugin.hpp>
#include <terminal/media/api/IExtensionFactory.hpp>
#include <terminal/media/impl/PluginRegistrar.hpp>
#include <map>

namespace terminal {
  namespace media {
    struct PluginRegistrar::impl {
      std::map<api::uuid_type, api::IExtensionFactory *> factories_;
      std::map<std::tuple<api::ExtensionType, api::string>, api::uuid_type> type_map_;
    };

    PluginRegistrar::PluginRegistrar() :
      pimpl_{ }
    {
    }

    PluginRegistrar::~PluginRegistrar() {

    }

    void PluginRegistrar::registerPlugin(api::IPlugin *plugin) {
      plugin->registerExtensions(this);
    }

    void PluginRegistrar::registerExtension(api::IExtensionFactory *extension) {
      auto extensionInfo(extension->getExtensionInfo());
      auto uuid(extensionInfo->uuid);
      auto type(extensionInfo->type);
      auto name(extensionInfo->name);

      pimpl_->factories_.insert(std::pair<api::uuid_type, api::IExtensionFactory *>(uuid, extension));

      auto tuple = std::tuple<api::ExtensionType, api::string>(type, name);
      pimpl_->type_map_.insert(std::pair<std::tuple<api::ExtensionType, api::string>, api::uuid_type>(tuple, uuid));
    }

    api::IExtension *PluginRegistrar::createExtension(api::uuid_type const &uuid) const {
      api::IExtension *rv { nullptr };

      auto const i = pimpl_->factories_.find(uuid);

      if(i != pimpl_->factories_.end()) {
        rv = i->second->createExtension();
      }

      return rv;
    }

    api::IExtension *PluginRegistrar::createExtension(api::ExtensionType type, api::string const &name) const {
      api::IExtension *rv { nullptr };

      auto const i = pimpl_->type_map_.find(std::tuple<api::ExtensionType, api::string>(type, name));

      if(i != pimpl_->type_map_.end()) {
        rv = createExtension(i->second);
      }

      return rv;
    }
  }
}


