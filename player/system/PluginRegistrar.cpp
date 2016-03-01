#include <terminal/media/api/IPlugin.hpp>
#include "PluginRegistrar.hpp"

namespace terminal {
  namespace media {
    PluginRegistrar::PluginRegistrar() {

    }

    PluginRegistrar::~PluginRegistrar() {

    }

    void PluginRegistrar::registerPlugin(api::IPlugin *plugin) {
      plugin->registerExtensions(this);
    }

    void PluginRegistrar::registerExtension(api::IExtensionFactory *extension) {

    }
  }
}


