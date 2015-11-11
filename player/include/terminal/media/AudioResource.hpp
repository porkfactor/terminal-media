#ifndef INCLUDE_TERMINAL_MEDIA_AUDIORESOURCE_HPP_
#define INCLUDE_TERMINAL_MEDIA_AUDIORESOURCE_HPP_

#include <terminal/media/MediaResource.hpp>

namespace terminal {
  namespace media {
    class AudioResource : public MediaResource {
    public:
      AudioResource(string const &);

      string const &getTitle() const;

      void setTitle(string const &);

    private:
      string title_;
    };
  }
}

#endif
