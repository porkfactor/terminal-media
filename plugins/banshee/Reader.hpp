#ifndef TERMINAL_MEDIA_BANSHEE_READER_HPP_
#define TERMINAL_MEDIA_BANSHEE_READER_HPP_

#include <terminal/media/api/Types.hpp>
#include <terminal/media/pimpl.hpp>
#include <memory>

namespace terminal {
  namespace media {
    namespace banshee {
      class Album;
      class Artist;
      class Library;

      class Reader {
      public:
        Reader(terminal::media::api::string const &);
        virtual ~Reader() = default;

        terminal::media::banshee::Library *loadLibrary();

      protected:
        void loadArtist(terminal::media::banshee::Artist *);
        void loadAlbum(terminal::media::banshee::Album *);

      private:
        struct impl;
        pimpl<impl> pimpl_;
      };
    }
  }
}

#endif
