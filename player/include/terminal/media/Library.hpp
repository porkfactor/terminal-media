#ifndef INCLUDE_TERMINAL_MEDIA_LIBRARY_HPP_
#define INCLUDE_TERMINAL_MEDIA_LIBRARY_HPP_

#include <vector>
#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    class Album;
    class AudioResource;
    class MediaResource;

    class Library {
    public:
      Library();

      album_ptr createAlbum(artist_ptr &, string const &);
      audio_ptr createAudioResource(album_ptr &, string const &);
      artist_ptr createArtist(string const &);

      std::vector<album_ptr> const &getAlbums() const;
      std::vector<artist_ptr> const &getArtists() const;

    private:
      std::vector<audio_ptr> media_;
      std::vector<album_ptr> albums_;
    };
  }
}

#endif
