#ifndef TERMINAL_MEDIA_MEDIAPLAYER_HPP_
#define TERMINAL_MEDIA_MEDIAPLAYER_HPP_

#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    class MediaPlayer {
    public:
      MediaPlayer();

      void Execute();

    private:
      api::string workingDirectory_;
      api::string pluginDirectory_;
    };
  }
}



#endif
