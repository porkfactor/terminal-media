#ifndef PLUGINS_BANSHEE_LIBRARY_HPP_
#define PLUGINS_BANSHEE_LIBRARY_HPP_

#include <terminal/media/api/ILibraryManager.hpp>
#include <terminal/media/api/Types.hpp>

namespace terminal {
  namespace media {
    namespace api {
      class IPlugin;
    }

    namespace banshee {
      class LibraryManager : public terminal::media::api::ILibraryManager {
      public:
        LibraryManager();

        void importLibrary() override;
        void exportLibrary() override;

        static terminal::media::api::ExtensionInfo const *getExtensionInfo();

      private:
        static terminal::media::api::ExtensionInfo extensionInfo_;
      };
    }
  }
}

#endif
