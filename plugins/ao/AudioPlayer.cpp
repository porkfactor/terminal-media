#include "AudioPlayer.hpp"

#include <thread>
#include <mutex>
#include <ao/ao.h>

std::once_flag once;

namespace terminal {
  namespace media {
    namespace ao {
      terminal::media::api::ExtensionInfo AudioPlayer::extensionInfo_ {
        { 1, 0, 0, 0, },
        terminal::media::api::ExtensionType::EXTENSION_AUDIO_INTERFACE,
        { 0, },
        "ao",
      };

      struct AudioPlayer::impl {
        impl() : device{nullptr,ao_close} {

        }

        std::unique_ptr<::ao_device, int (*)(::ao_device *)> device;
      };

      AudioPlayer::AudioPlayer() :
        pimpl_{}
      {
        std::call_once(once, []() { ao_initialize(); });
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
