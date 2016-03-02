#ifndef AOPLAYER_HPP_
#define AOPLAYER_HPP_

#include <terminal/media/api/IAudioPlayer.hpp>
#include <memory>

namespace plugin = terminal::media::plugin;

namespace terminal {
  namespace media {
    namespace ao {
      class AOPlayer : public plugin::IAudioPlayer {
      public:
        AOPlayer();

        virtual void play(string const &);

      private:
        struct impl;
        std::unique_ptr<impl> pimpl;
      };
    }
  }
}

#endif
