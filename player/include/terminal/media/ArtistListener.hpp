#ifndef INCLUDE_TERMINAL_MEDIA_ARTISTLISTENER_HPP_
#define INCLUDE_TERMINAL_MEDIA_ARTISTLISTENER_HPP_

namespace terminal {
  namespace media {
    class Artist;

    class ArtistListener {
    public:
      virtual ~ArtistListener() = default;

      virtual void notifyDelete(Artist const &);
      virtual void notifyRename(Artist const &);

    private:
    };
  }
}

#endif
