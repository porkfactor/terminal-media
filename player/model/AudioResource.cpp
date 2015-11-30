#include <terminal/media/AudioResource.hpp>

namespace terminal {
  namespace media {
    AudioResource::AudioResource(album_ptr album, string const &title, string const &uri) :
      MediaResource(uri),
      album_(album),
      title_(title)
    {
    }

    album_wptr AudioResource::getAlbum() const {
      return album_;
    }

    string const &AudioResource::getTitle() const {
      return title_;
    }

    string const &AudioResource::getURI() const {
      return uri_;
    }

    void AudioResource::setAlbum(album_ptr album) {
      album_ = album;
    }

    void AudioResource::setTitle(string const &title) {
      title_ = title;
    }

    void AudioResource::setURI(string const &uri) {
      uri_ = uri;
    }
  }
}
