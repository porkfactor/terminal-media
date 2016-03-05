#ifndef TERMINAL_MEDIA_PLUGIN_IAUDIOPLAYER_HPP_
#define TERMINAL_MEDIA_PLUGIN_IAUDIOPLAYER_HPP_

#include <terminal/media/api/IExtension.hpp>
#include <terminal/media/api/Types.hpp>

namespace terminal {
  namespace media {
    namespace api {
      class IAudioPlayer : public IExtension {
      public:
        virtual ~IAudioPlayer() = default;

        virtual void play(terminal::media::api::string const &) = 0;
        virtual void pause() = 0;
        virtual void stop() = 0;
        virtual void resume() = 0;

      private:
      };
    }
  }
}

#endif
