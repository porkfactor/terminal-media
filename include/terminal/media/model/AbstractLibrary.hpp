#ifndef TERMINAL_MEDIA_API_ABSTRACTLIBRARY_HPP_
#define TERMINAL_MEDIA_API_ABSTRACTLIBRARY_HPP_

#include <terminal/media/api/Types.hpp>
#include <memory>
#include <map>

namespace terminal {
  namespace media {
    namespace model {
      class AbstractArtist;

      class AbstractLibrary {
      protected:
        AbstractLibrary();

      public:
        virtual ~AbstractLibrary() = default;

        AbstractArtist *getArtist(terminal::media::api::string const &) const;

      private:
        std::map<terminal::media::api::string, std::unique_ptr<AbstractArtist>> artists_;
      };
    }
  }
}

#endif
