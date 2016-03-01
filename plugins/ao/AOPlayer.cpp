#include "AOPlayer.hpp"
#include <thread>
#include <mutex>
#include <ao/ao.h>

std::once_flag once;

namespace terminal {
  namespace media {
    namespace ao {
      struct AOPlayer::impl {
        std::unique_ptr<::ao_device, int (*)(::ao_device *)> device;
      };

      AOPlayer::AOPlayer() {
        std::call_once(once, []() { ao_initialize(); });
      }

      void AOPlayer::play(string const &path) {

      }
    }
  }
}
