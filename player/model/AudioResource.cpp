#include <terminal/media/AudioResource.hpp>

namespace terminal {
  namespace media {
    AudioResource::AudioResource(string const &uri) :
      MediaResource(uri)
    {
    }

    string const &AudioResource::getTitle() const {
      return title_;
    }

    void AudioResource::setTitle(string const &title) {
      title_ = title;
    }
  }
}
