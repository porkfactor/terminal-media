#ifndef INCLUDE_TERMINAL_MEDIA_ARTIST_HPP_
#define INCLUDE_TERMINAL_MEDIA_ARTIST_HPP_

#include <terminal/media/Media.hpp>
#include <vector>
#include <memory>

namespace terminal {
  namespace media {
    class ArtistListener;

    class Artist {
    public:
      Artist(string const &);
      ~Artist();

      string const &getName() const;

      void setName(string const &);

      void addListener(std::shared_ptr<ArtistListener> &);
      void removeListener(std::shared_ptr<ArtistListener> &);

    private:
      std::vector<std::weak_ptr<ArtistListener> > listeners_;
      string name_;
    };
  }
}

#endif
