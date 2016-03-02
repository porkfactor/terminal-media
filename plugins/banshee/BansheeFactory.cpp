#include "BansheeFactory.hpp"
#include "BansheeLibrary.hpp"

namespace terminal {
  namespace media {
    namespace banshee {
      BansheeFactory::BansheeFactory(terminal::media::api::IPlugin *plugin) :
        terminal::media::api::IExtensionFactory(plugin)
      {

      }

      BansheeFactory::~BansheeFactory() {

      }

      terminal::media::api::ExtensionInfo const *BansheeFactory::getExtensionInfo() const {
        return BansheeLibrary::getExtensionInfo();
      }

      terminal::media::api::IExtension *BansheeFactory::createExtension() {
        return new BansheeLibrary();
      }

      void BansheeFactory::destroyExtension(terminal::media::api::IExtension *extension) {
        delete extension;
      }
    }
  }
}
