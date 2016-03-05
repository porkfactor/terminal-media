#include "AudioResource.hpp"
#include "Album.hpp"

namespace terminal {
  namespace media {
    namespace banshee {
      AudioResource::AudioResource(
          terminal::media::banshee::Album *album,
          terminal::media::api::string const &title,
          terminal::media::api::string const &uri) :
        terminal::media::model::AbstractAudioResource(album, title, uri)
      {

      }
    }
  }
}
