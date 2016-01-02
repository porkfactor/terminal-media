#include <terminal/media/Plugin.hpp>
#include <terminal/media/Module.hpp>

namespace terminal {
  namespace media {
    struct Plugin::impl {
      std::unique_ptr<Module> module_;
    };

    Plugin::Plugin(string const &path) :
      pimpl_(new impl())
    {
      try {
        pimpl_->module_.reset(new Module(path));
      } catch(std::exception &e) {

      }
    }
  }
}


