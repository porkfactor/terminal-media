#ifndef PLUGINS_BANSHEE_LIBRARY_HPP_
#define PLUGINS_BANSHEE_LIBRARY_HPP_

#include <terminal/media/api/ILibraryManager.hpp>

namespace terminal {
  namespace media {
    namespace banshee {
      class BansheeLibrary : public terminal::media::api::ILibraryManager {
      public:
        virtual void open();
        virtual void close();

      private:
      };
    }
  }
}

#endif
