#ifndef MODEL_BANSHEE_AUDIORESOURCE_HPP_
#define MODEL_BANSHEE_AUDIORESOURCE_HPP_

#include <terminal/media/model/AbstractAudioResource.hpp>

namespace terminal {
  namespace media {
    namespace banshee {
      class Album;

      class AudioResource : public terminal::media::model::AbstractAudioResource {
      public:
        AudioResource(
            terminal::media::banshee::Album *album,
            terminal::media::api::string const &title,
            terminal::media::api::string const &uri
        );

      private:
      };
    }
  }
}

#endif
