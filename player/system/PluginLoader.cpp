#include <dlfcn.h>

namespace terminal {
  namespace media {
    class Module {
    public:
      Module(string const &path);

    private:
      void *handle_;
    };

    class PluginLoader {
    public:
      PluginLoader();

      void Load(string const &);
      void LoadModule(string const &);
    };

    PluginLoader::PluginLoader() {

    }

    void PluginLoader::Load(string const &name) {

    }

    void PluginLoader::LoadModule(string const &path) {

    }

    Module::Module(string const &path) :
      handle_(nullptr)
    {
      if((handle_ = dlopen(path.c_str(), RTLD_NOW | RTLD_LOCAL)) != nullptr) {

      } else {
        throw std::runtime_error("failed to load module");
      }
    }
  }
}
