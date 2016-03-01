#include <terminal/media/impl/PluginManager.hpp>
#include <terminal/media/impl/Plugin.hpp>
#include <terminal/media/api/IRegistrar.hpp>
#include <terminal/core/Logger.hpp>
#include <dirent.h>

namespace api = terminal::media::api;

namespace terminal {
  namespace media {
    PluginManager::PluginManager(api::IRegistrar *registrar) :
      registrar_(registrar)
    {

    }

    void PluginManager::Load(string const &path) {
      try {
        Plugin *p { new Plugin { path } };
        registrar_->registerPlugin(p);
      } catch(std::exception &e) {
        Log(Logger::ERROR, string(e.what()));
      }
    }

    void PluginManager::ScanDirectory(string const &path) {
      DIR *directory = 0;

      if((directory = opendir(path.c_str())) != nullptr) {
        struct dirent *d;

        while((d = readdir(directory)) != nullptr) {
          switch(d->d_type) {
          case DT_REG:
          case DT_LNK:
            Load(path + "/" + string(d->d_name));
            break;

          default:
            break;
          }
        }
      }
    }
  }
}
