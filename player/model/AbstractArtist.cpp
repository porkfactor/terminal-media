#include <terminal/media/model/AbstractArtist.hpp>

namespace terminal {
  namespace media {
    namespace model {
      AbstractArtist::AbstractArtist(AbstractLibrary *library, terminal::media::api::string const &name) :
        library_(library),
        name_(name)
      {

      }

      terminal::media::api::string const &AbstractArtist::getName(void) const {
        return name_;
      }
    }
  }
}
