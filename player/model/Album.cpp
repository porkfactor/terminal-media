#include <terminal/media/player/Album.hpp>
#include <terminal/media/player/AudioResource.hpp>

namespace terminal {
  namespace media {
    namespace model {
      Album::Album(std::shared_ptr<Artist> artist, string const &title) :
        artist_(artist),
        title_(title)
      {

      }

      std::weak_ptr<Artist> Album::getArtist() const {
        return artist_;
      }

      string const &Album::getTitle() const {
        return title_;
      }

      void Album::setArtist(std::shared_ptr<Artist> artist) {
        artist_ = artist;
      }

      void Album::setTitle(string const &title) {
        title_ = title;
      }
    }
  }
}
