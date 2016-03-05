#ifndef AUDIOPLAYER_HPP_
#define AUDIOPLAYER_HPP_

#include <terminal/media/api/IAudioPlayer.hpp>
#include <terminal/media/pimpl.hpp>
#include <memory>

namespace terminal {
  namespace media {
    namespace mpg123 {
      class AudioPlayer : public terminal::media::api::IAudioPlayer {
      public:
        AudioPlayer();

        virtual void play(terminal::media::api::string const &) override;
        virtual void stop(void) override;
        virtual void pause(void) override;
        virtual void resume(void) override;

        static terminal::media::api::ExtensionInfo const *getExtensionInfo();

      private:
        static terminal::media::api::ExtensionInfo extensionInfo_;

        struct impl;
        pimpl<impl> pimpl_;
      };
    }
  }
}

#endif
