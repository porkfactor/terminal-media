#ifndef TERMINAL_MEDIA_PLUGIN_ILIBRARYMANAGER_HPP_
#define TERMINAL_MEDIA_PLUGIN_ILIBRARYMANAGER_HPP_

#include <terminal/media/plugin/IPluginArtefact.hpp>

namespace terminal {
  namespace media {
    namespace plugin {
      class ILibraryManager : public IPluginArtefact {
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
