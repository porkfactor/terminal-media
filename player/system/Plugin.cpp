#include <terminal/media/Plugin.hpp>
#include <terminal/media/Module.hpp>

namespace terminal {
  namespace media {
    Plugin::Plugin(string const &path) :
      module_(new Module(path))
    {
      initialize_ = module_->GetMethod<void (void)>("Initialize");
      deInitialize_ = module_->GetMethod<void (void)>("DeInitialize");
      createArtefact_ = module_->GetMethod<plugin::IPluginArtefact *(void)>("CreateArtefact");
      destroyArtefact_ = module_->GetMethod<void (plugin::IPluginArtefact *)>("DestroyArtefact");
    }


    void Plugin::Initialize() {
      initialize_();
    }

    void Plugin::DeInitialize() {
      deInitialize_();
    }

    plugin::IPluginArtefact *Plugin::CreateArtefact() {
      return createArtefact_();
    }

    void Plugin::DestroyArtefact(plugin::IPluginArtefact *artefact) {
      destroyArtefact_(artefact);
    }
  }
}


