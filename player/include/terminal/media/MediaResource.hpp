#ifndef INCLUDE_TERMINAL_MEDIA_MEDIARESOURCE_HPP_
#define INCLUDE_TERMINAL_MEDIA_MEDIARESOURCE_HPP_

#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    class MediaResource {
    public:
      MediaResource(string const &);
      virtual ~MediaResource() = default;

      string const &getUri() const;

      void setUri(string const &);

    private:
      string uri_;
    };
  }
}

#endif
