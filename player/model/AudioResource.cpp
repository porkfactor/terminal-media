#include <terminal/media/player/AudioResource.hpp>

namespace terminal {
  namespace media {
    namespace model {
      AudioResource::AudioResource(std::shared_ptr<Album> album, string const &title, string const &uri) :
        MediaResource(uri),
        album_(album),
        title_(title)
      {
      }

      std::weak_ptr<Album> AudioResource::getAlbum() const {
        return album_;
      }

      string const &AudioResource::getTitle() const {
        return title_;
      }

      string const &AudioResource::getURI() const {
        return uri_;
      }

      void AudioResource::setAlbum(std::shared_ptr<Album> album) {
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
}
