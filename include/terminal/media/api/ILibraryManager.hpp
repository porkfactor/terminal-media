#ifndef TERMINAL_MEDIA_PLUGIN_ILIBRARYMANAGER_HPP_
#define TERMINAL_MEDIA_PLUGIN_ILIBRARYMANAGER_HPP_

#include <terminal/media/api/IExtension.hpp>

namespace terminal {
  namespace media {
    namespace api {
      class ILibraryManager : public IExtension {
      public:
        virtual ~ILibraryManager() = default;

        virtual void importLibrary() = 0;
        virtual void exportLibrary() = 0;

      private:
      };
    }
  }
}

#endif
