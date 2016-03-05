#include <terminal/media/model/AbstractLibrary.hpp>

namespace terminal {
  namespace media {
    namespace banshee {
      class Library : public terminal::media::model::AbstractLibrary {
      public:
        Library(terminal::media::api::string const &path);

      private:
      };
    }
  }
}
