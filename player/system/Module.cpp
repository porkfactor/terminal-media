#include <terminal/media/Module.hpp>
#include <dlfcn.h>

namespace terminal {
  namespace media {
    struct Module::impl {
      impl(string const &path) :
        dl_handle_(dlopen(path.c_str(), RTLD_NOW | RTLD_LOCAL), dlclose),
        magic_(Module::INVALID_MAGIC),
        capabilities_(0)
      {
      }

      typename Module::magic_type magic_;
      typename Module::capabilities_type capabilities_;
      std::unique_ptr<void, int (*)(void *)> dl_handle_;
    };

    Module::Module(string const &path) :
      pimpl_(new impl(path))
    {
      if(pimpl_->dl_handle_) {
      } else {
        throw std::runtime_error(dlerror());
      }
    }

    Module::~Module() {

    }
  }
}
