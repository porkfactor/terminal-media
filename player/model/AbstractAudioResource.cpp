#include <terminal/media/model/AbstractAudioResource.hpp>

namespace terminal {
  namespace media {
    namespace model {
      AbstractAudioResource::AbstractAudioResource(
          AbstractAlbum *album,
          terminal::media::api::string const &title,
          terminal::media::api::string const &uri
      ) :
          AbstractMediaResource(uri)
      {

      }
    }
  }
}
