#include "LibraryManager.hpp"
#include "model/banshee/Library.hpp"
#include "Reader.hpp"

namespace banshee = terminal::media::banshee;

namespace terminal {
  namespace media {
    namespace banshee {
      terminal::media::api::ExtensionInfo LibraryManager::extensionInfo_ {
        { 1, 0, 0, 0, },
        terminal::media::api::ExtensionType::EXTENSION_LIBRARY_MANAGER,
        { 0, },
        "banshee",
      };

      LibraryManager::LibraryManager() {
      }

      void LibraryManager::importLibrary() {
        terminal::media::model::AbstractLibrary *library{new banshee::Library("")};
        banshee::Reader *reader{new banshee::Reader("/home/localadmin/.config/banshee-1/banshee.db")};

        reader->loadLibrary();
      }

      void LibraryManager::exportLibrary() {

      }

      terminal::media::api::ExtensionInfo const *LibraryManager::getExtensionInfo() {
        return &extensionInfo_;
      }
    }
  }
}
