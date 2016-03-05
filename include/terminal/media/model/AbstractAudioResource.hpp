#ifndef TERMINAL_MEDIA_API_ABSRACTAUDIORESOURCE_HPP_
#define TERMINAL_MEDIA_API_ABSRACTAUDIORESOURCE_HPP_

#include <terminal/media/model/AbstractMediaResource.hpp>

namespace terminal {
  namespace media {
    namespace model {
      class AbstractAlbum;

      class AbstractAudioResource : public AbstractMediaResource {
      public:
        AbstractAudioResource(
            AbstractAlbum *album,
            terminal::media::api::string const &title,
            terminal::media::api::string const &uri
        );
        virtual ~AbstractAudioResource() = default;

        AbstractAlbum *getAlbum() const;
        AbstractArtist *getArtist() const;

      private:
        AbstractAlbum *album_;
      };
    }
  }
}

#endif
