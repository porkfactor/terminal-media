#ifndef BANSHEE_ALBUM_HPP_
#define BANSHEE_ALBUM_HPP_

#include <terminal/media/model/AbstractAlbum.hpp>

namespace terminal {
  namespace media {
    namespace banshee {
      class Artist;

      class Album : public terminal::media::model::AbstractAlbum {
      public:
        Album(
            terminal::media::banshee::Artist *,
            terminal::media::api::string const &name,
            int id
        );

        int getId() const;

      private:
        int id_;
      };
    }
  }
}



#endif
