#ifndef INCLUDE_TERMINAL_MEDIA_ALBUM_HPP_
#define INCLUDE_TERMINAL_MEDIA_ALBUM_HPP_

#include <terminal/media/Media.hpp>
#include <memory>
#include <vector>

namespace terminal {
  namespace media {
    class Artist;
    class AudioResource;

    class Album {
    public:
      Album(artist_ptr &, string const &);

      artist_wptr getArtist() const;
      string const &getTitle() const;

      void setArtist(artist_ptr &);
      void setTitle(string const &);

    private:
      string title_;
      artist_wptr artist_;
      std::vector<audio_ptr> tracks_;
    };
  }
}

#endif
