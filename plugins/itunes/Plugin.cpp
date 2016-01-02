#include <terminal/media/plugin/IRegistrar.hpp>
#include <terminal/media/plugin/IPlugin.hpp>

namespace plugin = terminal::media::plugin;

extern "C" void PluginInit() {

}

extern "C" void PluginDeinit() {

}

static const plugin::PluginInfo iTunesPlugin = {
  plugin::PluginVersion { 1, 0, 0, 0, },
  plugin::PluginType::PLUGIN_LIBRARY_MANAGER
};

extern "C" void registerPlugin(terminal::media::plugin::IRegistrar *registrar) {
  plugin::IPlugin *plugin = registrar->registerPlugin(&iTunesPlugin);
}

