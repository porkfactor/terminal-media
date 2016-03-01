#ifndef INCLUDE_TERMINAL_MEDIA_MODEL_AUDIORESOURCE_HPP_
#define INCLUDE_TERMINAL_MEDIA_MODEL_AUDIORESOURCE_HPP_

#include <terminal/media/player/MediaResource.hpp>
#include <memory>

namespace terminal {
  namespace media {
    namespace model {
      class Album;
      class Artist;

      class AudioResource : public MediaResource {
      public:
        AudioResource(std::shared_ptr<Album>, string const &, string const &);

        std::weak_ptr<Album> getAlbum() const;
        string const &getTitle() const;
        string const &getURI() const;

        void setAlbum(std::shared_ptr<Album>);
        void setTitle(string const &);
        void setURI(string const &);

      private:
        string title_;
        string uri_;
        std::weak_ptr<Album> album_;
      };
    }
  }
}

#endif
