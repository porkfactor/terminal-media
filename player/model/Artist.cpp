#include <terminal/media/Media.hpp>
#include <terminal/media/player/Artist.hpp>
#include <terminal/media/player/ArtistListener.hpp>

namespace terminal {
  namespace media {
    namespace model {
      Artist::Artist(string const &name) :
        name_(name)
      {
      }

      Artist::~Artist() {
        for(auto i : listeners_) {
          if(auto p = i.lock()) {
            p->notifyDelete(*this);
          }
        }
      }

      void Artist::setName(string const &name) {
        name_ = name;
      }

      void Artist::addListener(std::shared_ptr<ArtistListener> &listener) {
        listeners_.push_back(listener);
      }
    }
  }
}
