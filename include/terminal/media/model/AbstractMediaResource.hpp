#ifndef TERMINAL_MEDIA_API_ABSTRACTMEDIARESOURCE_HPP_
#define TERMINAL_MEDIA_API_ABSTRACTMEDIARESOURCE_HPP_

#include <terminal/media/api/Types.hpp>

namespace terminal {
  namespace media {
    namespace model {
      class AbstractArtist;

      class AbstractMediaResource {
      public:
        AbstractMediaResource(terminal::media::api::string const &uri);
        virtual ~AbstractMediaResource() = default;

        AbstractArtist *getArtist() const;
        terminal::media::api::string const &getURI() const;

      private:
        terminal::media::api::string uri_;
      };
    }
  }
}

#endif
