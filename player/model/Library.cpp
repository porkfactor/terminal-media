#include <terminal/media/player/Library.hpp>
#include <terminal/media/player/Album.hpp>
#include <terminal/media/player/Artist.hpp>
#include <terminal/media/player/AudioResource.hpp>

namespace terminal {
  namespace media {
    namespace model {
      Library::Library() {

      }

      std::shared_ptr<Artist> Library::createArtist(string const &name) {
        std::shared_ptr<Artist> artist{ std::make_shared<Artist>(name) };

        return artist;
      }

      std::shared_ptr<Album> Library::createAlbum(std::shared_ptr<Artist> artist, string const &name) {
        std::shared_ptr<Album> album{ std::make_shared<Album>(artist, name) };

        return album;
      }

      std::shared_ptr<AudioResource> createAudioResource(std::shared_ptr<Album> album, string const &name) {
        std::shared_ptr<AudioResource> audio{ std::make_shared<AudioResource>(album, name, "") };

        return audio;
      }
    }
  }
}
