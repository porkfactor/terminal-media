#ifndef INCLUDE_TERMINAL_MEDIA_MODEL_ALBUM_HPP_
#define INCLUDE_TERMINAL_MEDIA_MODEL_ALBUM_HPP_

#include <terminal/media/Media.hpp>
#include <memory>
#include <vector>

namespace terminal {
  namespace media {
    namespace model {
      class Artist;
      class AudioResource;

      class Album {
      public:
        Album(std::shared_ptr<Artist>, string const &);

        std::weak_ptr<Artist> getArtist() const;
        string const &getTitle() const;

        void setArtist(std::shared_ptr<Artist>);
        void setTitle(string const &);

      private:
        string title_;
        std::weak_ptr<Artist> artist_;
        std::vector<std::shared_ptr<AudioResource>> tracks_;
      };
    }
  }
}

#endif
