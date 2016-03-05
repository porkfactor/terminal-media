#include "Album.hpp"
#include "Artist.hpp"

namespace terminal {
  namespace media {
    namespace banshee {
      Album::Album(
          terminal::media::banshee::Artist *artist,
          terminal::media::api::string const &title,
          int id) :
        terminal::media::model::AbstractAlbum(artist, title),
        id_(id)
      {

      }

      int Album::getId() const {
        return id_;
      }
    }
  }
}
