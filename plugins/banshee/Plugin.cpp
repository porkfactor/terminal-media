#include <terminal/media/api/IRegistrar.hpp>
#include <terminal/media/api/IPlugin.hpp>
#include "BansheeFactory.hpp"

namespace api = terminal::media::api;

extern "C" void initialize() {

}

extern "C" void deInitialize() {

}

static const api::PluginInfo bansheePlugin = {
  api::PluginVersion { 1, 0, 0, 0, },
  api::PluginType::PLUGIN_LIBRARY_MANAGER
};

extern "C" void registerExtensions(api::IPlugin *plugin, api::IRegistrar *registrar) {
  registrar->registerExtension(new terminal::media::banshee::BansheeFactory(plugin));
}

extern "C" void deregisterExtensions(api::IPlugin *plugin, api::IRegistrar *registrar) {

}
