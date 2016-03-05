#include "ExtensionFactory.hpp"

#include "LibraryManager.hpp"

namespace terminal {
  namespace media {
    namespace banshee {
      ExtensionFactory::ExtensionFactory(terminal::media::api::IPlugin *plugin) :
        terminal::media::api::IExtensionFactory(plugin)
      {

      }

      ExtensionFactory::~ExtensionFactory() {

      }

      terminal::media::api::ExtensionInfo const *ExtensionFactory::getExtensionInfo() const {
        return LibraryManager::getExtensionInfo();
      }

      terminal::media::api::IExtension *ExtensionFactory::createExtension() {
        return new LibraryManager();
      }

      void ExtensionFactory::destroyExtension(terminal::media::api::IExtension *extension) {
        delete extension;
      }
    }
  }
}
