#include <terminal/media/player/MediaResource.hpp>

namespace terminal {
  namespace media {
    namespace model {
      MediaResource::MediaResource(string const &uri) :
        uri_(uri)
      {

      }

      string const &MediaResource::getUri() const {
        return uri_;
      }

      void MediaResource::setUri(string const &uri) {
        uri_ = uri;
      }
    }
  }
}
