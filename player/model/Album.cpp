#include <terminal/media/Album.hpp>
#include <terminal/media/AudioResource.hpp>

namespace terminal {
  namespace media {
    Album::Album(artist_ptr &artist, string const &title) :
      artist_(artist),
      title_(title)
    {

    }

    artist_wptr Album::getArtist() const {
      return artist_;
    }

    string const &Album::getTitle() const {
      return title_;
    }

    void Album::setArtist(artist_ptr &artist) {
      artist_ = artist;
    }

    void Album::setTitle(string const &title) {
      title_ = title;
    }
  }
}
