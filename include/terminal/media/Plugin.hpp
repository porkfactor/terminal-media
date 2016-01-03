#ifndef TERMINAL_MEDIA_PLUGIN_HPP_
#define TERMINAL_MEDIA_PLUGIN_HPP_

#include <terminal/media/Media.hpp>
#include <terminal/media/plugin/IPlugin.hpp>
#include <terminal/media/Module.hpp>
#include <functional>

namespace terminal {
  namespace media {
    class Plugin : public plugin::IPlugin {
    public:
      Plugin(string const &path);

      void Initialize();
      void DeInitialize();

      plugin::IPluginArtefact *CreateArtefact();
      void DestroyArtefact(plugin::IPluginArtefact *);

    private:
      std::unique_ptr<Module> module_;

      std::function<void(void)> initialize_;
      std::function<void(void)> deInitialize_;
      std::function<plugin::IPluginArtefact *(void)> createArtefact_;
      std::function<void (plugin::IPluginArtefact *)> destroyArtefact_;
    };
  }
}



#endif
