#ifndef TERMINAL_MEDIA_API_ABSTRACTARTIST_HPP_
#define TERMINAL_MEDIA_API_ABSTRACTARTIST_HPP_

#include <terminal/media/api/Types.hpp>

namespace terminal {
  namespace media {
    namespace model {
      class AbstractLibrary;

      class AbstractArtist {
      protected:
        AbstractArtist(AbstractLibrary *, terminal::media::api::string const &name);

      public:
        virtual ~AbstractArtist() = default;

        terminal::media::api::string const &getName() const;
        void setName(terminal::media::api::string const &);

      private:
        AbstractLibrary *library_;
        terminal::media::api::string name_;
      };
    }
  }
}

#endif
