#ifndef TERMINAL_MEDIA_PLUGIN_ILIBRARYMANAGER_HPP_
#define TERMINAL_MEDIA_PLUGIN_ILIBRARYMANAGER_HPP_

#include "IExtension.hpp"

namespace terminal {
  namespace media {
    namespace api {
      class ILibraryManager : public IExtension {
      public:
        virtual ~ILibraryManager() = default;

        void open();
        void close();

      private:
      };
    }
  }
}

#endif
