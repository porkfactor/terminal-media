#ifndef INCLUDE_TERMINAL_MEDIA_MODEL_LIBRARY_HPP_
#define INCLUDE_TERMINAL_MEDIA_MODEL_LIBRARY_HPP_

#include <vector>
#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    namespace model {
      class Album;
      class Artist;
      class AudioResource;
      class MediaResource;

      class Library {
      public:
        Library();

        std::shared_ptr<Album> createAlbum(std::shared_ptr<Artist>, string const &);
        std::shared_ptr<AudioResource> createAudioResource(std::shared_ptr<Album>, string const &);
        std::shared_ptr<Artist> createArtist(string const &);

        std::vector<std::shared_ptr<Album>> const &getAlbums() const;
        std::vector<std::shared_ptr<Artist>> const &getArtists() const;

      private:
        std::vector<std::shared_ptr<AudioResource>> media_;
        std::vector<std::shared_ptr<Album>> albums_;
        std::vector<std::shared_ptr<Artist>> artists_;
      };
    }
  }
}

#endif
