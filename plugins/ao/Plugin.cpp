#include <terminal/media/api/IRegistrar.hpp>
#include <terminal/media/api/IPlugin.hpp>

namespace api = terminal::media::api;

extern "C" void initialize() {

}

extern "C" void uninitialize() {

}

static const api::PluginInfo aoPlugin = {
  api::PluginVersion { 1, 0, 0, 0, },
  api::PluginType::PLUGIN_AUDIO_INTERFACE,
};

extern "C" void registerExtensions(api::IPlugin *plugin, api::IRegistrar *registrar) {

}

extern "C" void deregisterExtensions(api::IPlugin *plugin, api::IRegistrar *registrar) {

}
