#ifndef TERMINAL_MEDIA_PLUGINMANAGER_HPP_
#define TERMINAL_MEDIA_PLUGINMANAGER_HPP_

#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    namespace api {
      class IRegistrar;
    }

    class PluginManager {
    public:
      PluginManager(api::IRegistrar *);

      void Load(string const &);
      void ScanDirectory(string const &);

    private:
      api::IRegistrar *registrar_;
    };
  }
}

#endif
