#include "Artist.hpp"
#include "Library.hpp"

namespace terminal {
  namespace media {
    namespace banshee {
      Artist::Artist(
          terminal::media::banshee::Library *library,
          terminal::media::api::string const &name,
          int id) :
        terminal::media::model::AbstractArtist(library, name),
        id_(id)
      {

      }

      int Artist::getId(void) const {
        return id_;
      }
    }
  }
}
