#include <terminal/media/model/AbstractAlbum.hpp>

namespace terminal {
  namespace media {
    namespace model {
      AbstractAlbum::AbstractAlbum(AbstractArtist *artist, terminal::media::api::string const &title) :
        artist_{artist},
        title_{title}
      {

      }

      terminal::media::api::string const &AbstractAlbum::getTitle(void) const {
        return title_;
      }
    }
  }
}
