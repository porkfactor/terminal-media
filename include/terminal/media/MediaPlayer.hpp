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
      string workingDirectory_;
      string pluginDirectory_;
    };
  }
}



#endif
