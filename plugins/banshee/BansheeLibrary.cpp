#include "BansheeLibrary.hpp"

namespace terminal {
  namespace media {
    namespace banshee {
      terminal::media::api::ExtensionInfo BansheeLibrary::extensionInfo_ {
        { 1, 0, 0, 0, },
        terminal::media::api::ExtensionType::EXTENSION_LIBRARY_MANAGER,
        { 0, },
        "banshee",
      };

      BansheeLibrary::BansheeLibrary() {
      }

      void BansheeLibrary::open() {

      }

      void BansheeLibrary::close() {

      }

      terminal::media::api::ExtensionInfo const *BansheeLibrary::getExtensionInfo() {
        return &extensionInfo_;
      }
    }
  }
}
