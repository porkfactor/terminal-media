#include <terminal/media/model/AbstractLibrary.hpp>
#include <terminal/media/model/AbstractArtist.hpp>

namespace terminal {
  namespace media {
    namespace model {
      AbstractLibrary::AbstractLibrary() {

      }

      AbstractArtist *AbstractLibrary::getArtist(terminal::media::api::string const &name) const {
        AbstractArtist *rv{nullptr};

        auto i = artists_.find(name);
        if(i != artists_.end()) {
          rv = i->second.get();
        }

        return rv;
      }
    }
  }
}
