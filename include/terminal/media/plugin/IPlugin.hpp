#ifndef TERMINAL_MEDIA_PLUGIN_IPLUGIN_HPP_
#define TERMINAL_MEDIA_PLUGIN_IPLUGIN_HPP_

namespace terminal {
  namespace media {
    namespace plugin {
      class IPluginArtefact;

      /**
       * Base representation of a Plugin.
       */
      class IPlugin {
      public:
        virtual ~IPlugin() = default;

        virtual void Initialize() = 0;
        virtual void DeInitialize() = 0;

        /**
         * Manufacture a new Artefact.
         *
         * @return New instance of IPluginArtefact as implemented by this plugin
         */
        virtual IPluginArtefact *CreateArtefact() = 0;
        /**
         * Destroy an Artefact.
         *
         * @param artefact The Artefact instance to destroy
         */
        virtual void DestroyArtefact(IPluginArtefact *artefact) = 0;

      private:

      };
    }
  }
}



#endif
