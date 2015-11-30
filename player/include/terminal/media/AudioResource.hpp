#ifndef INCLUDE_TERMINAL_MEDIA_AUDIORESOURCE_HPP_
#define INCLUDE_TERMINAL_MEDIA_AUDIORESOURCE_HPP_

#include <terminal/media/MediaResource.hpp>
#include <memory>

namespace terminal {
  namespace media {
    class Album;
    class Artist;

    class AudioResource : public MediaResource {
    public:
      AudioResource(album_ptr, string const &, string const &);

      album_wptr getAlbum() const;
      string const &getTitle() const;
      string const &getURI() const;

      void setAlbum(album_ptr);
      void setTitle(string const &);
      void setURI(string const &);

    private:
      string title_;
      string uri_;
      album_wptr album_;
    };
  }
}

#endif
