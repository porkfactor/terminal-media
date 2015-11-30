#ifndef PLUGINS_BANSHEE_LIBRARY_HPP_
#define PLUGINS_BANSHEE_LIBRARY_HPP_

#include <terminal/media/ImportableLibrary.hpp>

namespace terminal {
  namespace media {
    class Library;

    namespace banshee {
      class BansheeLibrary : public terminal::media::ImportableLibrary {
      public:

        void load(Library &);
        void save(Library const &);

      private:
      };
    }
  }
}

#endif
