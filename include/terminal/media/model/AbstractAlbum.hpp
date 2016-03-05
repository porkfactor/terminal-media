#ifndef TERMINAL_MEDIA_API_ABSTRACTALBUM_HPP_
#define TERMINAL_MEDIA_API_ABSTRACTALBUM_HPP_

#include <terminal/media/api/Types.hpp>

namespace terminal {
  namespace media {
    namespace model {
      class AbstractArtist;

      class AbstractAlbum {
      public:
        AbstractAlbum(AbstractArtist *artist, terminal::media::api::string const &title);
        virtual ~AbstractAlbum() = default;

        terminal::media::api::string const &getTitle() const;
        void setTitle(terminal::media::api::string const &);

      private:
        AbstractArtist *artist_;
        terminal::media::api::string const &title_;
      };
    }
  }
}

#endif
