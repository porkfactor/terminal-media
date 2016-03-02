#ifndef TERMINAL_MEDIA_PLUGIN_IEXTENSION_HPP_
#define TERMINAL_MEDIA_PLUGIN_IEXTENSION_HPP_

namespace terminal {
  namespace media {
    namespace api {
      class IExtension;
      class IPlugin;
      struct ExtensionInfo;

      class IExtensionFactory {
      public:
        IExtensionFactory(IPlugin *plugin) : plugin_(plugin) { };
        virtual ~IExtensionFactory() = default;

        IPlugin *getPlugin() const { return plugin_; };

        virtual ExtensionInfo const *getExtensionInfo() const = 0;

        /**
         * Manufacture a new Artefact.
         *
         * @return New instance of IPluginArtefact as implemented by this plugin
         */
        virtual IExtension *createExtension() = 0;
        /**
         * Destroy an Artefact.
         *
         * @param artefact The Artefact instance to destroy
         */
        virtual void destroyExtension(IExtension *) = 0;

      private:
        IPlugin *plugin_;
      };
    }
  }
}

#endif
