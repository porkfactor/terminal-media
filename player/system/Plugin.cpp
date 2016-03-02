#include <terminal/media/impl/Plugin.hpp>
#include <terminal/media/impl/Module.hpp>
#include <terminal/media/api/IRegistrar.hpp>
#include <functional>


namespace terminal {
  namespace media {
    struct Plugin::impl {
      impl(string const &path) : module_(new Module(path))
      {
        initialize_ = module_->getMethod<void (void)>("initialize");
        uninitialize_ = module_->getMethod<void (void)>("uninitialize");
        registerExtensions_ = module_->getMethod<void(api::IPlugin *, api::IRegistrar *)>("registerExtensions");
        deregisterExtensions_ = module_->getMethod<void(api::IPlugin *, api::IRegistrar *)>("deregisterExtensions");
      }

      std::unique_ptr<Module> module_;
      std::function<void(void)> initialize_;
      std::function<void(void)> uninitialize_;
      std::function<void(api::IPlugin *, api::IRegistrar *)> registerExtensions_;
      std::function<void(api::IPlugin *, api::IRegistrar *)> deregisterExtensions_;
    };

    Plugin::Plugin(string const &path) :
      pimpl_ { path }
    {
      initialize();
    }

    Plugin::~Plugin() {
      uninitialize();
    }

    void Plugin::initialize() {
      if(pimpl_->initialize_) {
        pimpl_->initialize_();
      }
    }

    void Plugin::uninitialize() {
      if(pimpl_->uninitialize_) {
        pimpl_->uninitialize_();
      }
    }

    void Plugin::registerExtensions(api::IRegistrar *registrar) {
      if(pimpl_->registerExtensions_) {
        pimpl_->registerExtensions_(this, registrar);
      }
    }

    void Plugin::deregisterExtensions(api::IRegistrar *registrar) {
      if(pimpl_->deregisterExtensions_) {
        pimpl_->deregisterExtensions_(this, registrar);
      }
    }
  }
}
