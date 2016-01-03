#include <terminal/media/PluginManager.hpp>
#include <terminal/media/Plugin.hpp>
#include <terminal/media/Logger.hpp>
#include <dirent.h>

namespace terminal {
  namespace media {
    PluginManager::PluginManager() {

    }

    void PluginManager::Load(string const &name) {

    }

    void PluginManager::ScanDirectory(string const &path) {
      DIR *directory = 0;

      if((directory = opendir(path.c_str())) != nullptr) {
        struct dirent *d;

        while((d = readdir(directory)) != nullptr) {
          switch(d->d_type) {
          case DT_REG:
          case DT_LNK:
            try {
              Plugin p { path + "/" + string(d->d_name) };
            } catch(std::exception &e) {
              Log(Logger::ERROR, string(e.what()));
            }
            break;

          default:
            break;
          }
        }
      }
    }
  }
}
