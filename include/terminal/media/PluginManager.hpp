#ifndef TERMINAL_MEDIA_PLUGINMANAGER_HPP_
#define TERMINAL_MEDIA_PLUGINMANAGER_HPP_

#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    class PluginManager {
    public:
      PluginManager();

      void Load(string const &);
      void ScanDirectory(string const &);

    private:
    };
  }
}

#endif
