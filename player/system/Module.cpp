#include <terminal/media/impl/Module.hpp>
#include <dlfcn.h>

namespace terminal {
  namespace media {
    Module::Module(string const &path) :
      dl_handle_(dlopen(path.c_str(), RTLD_NOW | RTLD_LOCAL), dlclose)
    {
      if(dl_handle_) {
      } else {
        throw std::runtime_error(dlerror());
      }
    }

    void *Module::getSymbol(string const &symbolName) {
      void *symbol = nullptr;
      char const *error = 0;

      if(((symbol = dlsym(dl_handle_.get(), symbolName.c_str())) != nullptr) ||
         ((error = dlerror()) == nullptr)) {

      } else {
        throw std::logic_error("can't find symbol \"" + symbolName + "\" : " + string(error));
      }

      return symbol;
    }
  }
}
