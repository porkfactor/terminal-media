#ifndef INCLUDE_TERMINAL_MEDIA_MODEL_ALBUMLISTENER_HPP_
#define INCLUDE_TERMINAL_MEDIA_MODEL_ALBUMLISTENER_HPP_

#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    namespace model {
      class Album;

      class AlbumListener {
        virtual ~AlbumListener() = default;

        virtual void notifyDelete(Album const &) = 0;
        virtual void notifyRename(Album const &) = 0;
      };
    }
  }
}

#endif
