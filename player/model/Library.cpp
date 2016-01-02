#include <terminal/media/Library.hpp>
#include <terminal/media/Album.hpp>
#include <terminal/media/Artist.hpp>
#include <terminal/media/AudioResource.hpp>

namespace terminal {
  namespace media {
    Library::Library() {

    }

    artist_ptr Library::createArtist(string const &name) {
      artist_ptr artist(new Artist(name));

      return artist;
    }

    album_ptr Library::createAlbum(artist_ptr &artist, string const &name) {
      album_ptr album(new Album(artist, name));

      return album;
    }

    audio_ptr createAudioResource(album_ptr &album, string const &name) {
      audio_ptr audio(new AudioResource(album, name, ""));

      return audio;
    }
  }
}
