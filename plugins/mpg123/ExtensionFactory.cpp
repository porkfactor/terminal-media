#include "ExtensionFactory.hpp"
#include "AudioPlayer.hpp"

namespace terminal {
  namespace media {
    namespace mpg123 {
      ExtensionFactory::ExtensionFactory(terminal::media::api::IPlugin *plugin) :
        terminal::media::api::IExtensionFactory(plugin)
      {

      }

      ExtensionFactory::~ExtensionFactory() {

      }

      terminal::media::api::ExtensionInfo const *ExtensionFactory::getExtensionInfo() const {
        return AudioPlayer::getExtensionInfo();
      }

      terminal::media::api::IExtension *ExtensionFactory::createExtension() {
        return new AudioPlayer();
      }

      void ExtensionFactory::destroyExtension(terminal::media::api::IExtension *extension) {
        delete extension;
      }
    }
  }
}
