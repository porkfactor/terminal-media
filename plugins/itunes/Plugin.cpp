#include <terminal/media/plugin/IRegistrar.hpp>
#include <terminal/media/plugin/IPlugin.hpp>

namespace plugin = terminal::media::plugin;

extern "C" void Initialize() {

}

extern "C" void DeInitialize() {

}

static const plugin::PluginInfo iTunesPlugin = {
  plugin::PluginVersion { 1, 0, 0, 0, },
  plugin::PluginType::PLUGIN_LIBRARY_MANAGER
};

extern "C" void registerPlugin(terminal::media::plugin::IRegistrar *registrar) {
  plugin::IPlugin *plugin = registrar->registerPlugin(&iTunesPlugin);
}

extern "C" terminal::media::plugin::IPluginArtefact *CreateArtefact(void) {
  return nullptr;
}

extern "C" void DestroyArtefact(terminal::media::plugin::IPluginArtefact *artefact) {

}

