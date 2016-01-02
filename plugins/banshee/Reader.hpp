#ifndef TERMINAL_MEDIA_BANSHEE_READER_HPP_
#define TERMINAL_MEDIA_BANSHEE_READER_HPP_

#include <terminal/media/Media.hpp>
#include <memory>

namespace terminal {
  namespace media {
    class Library;

    class LibraryImporter {

    };

    namespace banshee {
      class Reader : public LibraryImporter {
      public:
        Reader();
        Reader(terminal::media::string const &);

        void load(Library &);

      protected:
        void loadArtist(Library &, int, std::string const &);

      private:
        struct impl;
        std::unique_ptr<impl> pimpl_;
      };
    }
  }
}

#endif
