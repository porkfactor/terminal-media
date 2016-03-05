#include "AudioPlayer.hpp"

#include <thread>
#include <mutex>
#include <mpg123.h>
#include <out123.h>

std::once_flag mpg123_init_once;

namespace terminal {
  namespace media {
    namespace mpg123 {
      terminal::media::api::ExtensionInfo AudioPlayer::extensionInfo_ {
        { 1, 0, 0, 0, },
        terminal::media::api::ExtensionType::EXTENSION_AUDIO_INTERFACE,
        { 0, },
        "mpg123",
      };

      struct AudioPlayer::impl {
      };

      AudioPlayer::AudioPlayer() :
        pimpl_{}
      {
        std::call_once(mpg123_init_once, [](){ mpg123_init(); });
      }

      void AudioPlayer::play(terminal::media::api::string const &path) {

      }

      void AudioPlayer::stop() {

      }

      void AudioPlayer::resume() {

      }

      void AudioPlayer::pause() {

      }
    }
  }
}
