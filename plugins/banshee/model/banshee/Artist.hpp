#ifndef BANSHEEARTIST_HPP_
#define BANSHEEARTIST_HPP_

#include <terminal/media/model/AbstractArtist.hpp>

namespace terminal {
  namespace media {
    namespace banshee {
      class Library;

      class Artist : public terminal::media::model::AbstractArtist {
      public:
        Artist(
            terminal::media::banshee::Library *library,
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
