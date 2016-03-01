#ifndef TERMINAL_MEDIA_PLUGIN_IAUDIOPLAYER_HPP_
#define TERMINAL_MEDIA_PLUGIN_IAUDIOPLAYER_HPP_

#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    namespace plugin {
      class IAudioPlayer {
      public:
        virtual ~IAudioPlayer() = default;

        virtual void play(string const &);
        virtual void pause();
        virtual void stop();
        virtual void resume();

      private:
      };
    }
  }
}

#endif
