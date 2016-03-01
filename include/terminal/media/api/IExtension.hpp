#ifndef TERMINAL_MEDIA_PLUGIN_IEXTENSIONARTEFACT_HPP_
#define TERMINAL_MEDIA_PLUGIN_IEXTENSIONARTEFACT_HPP_

namespace terminal {
  namespace media {
    namespace api {
      class IExtension {
      public:
        virtual ~IExtension() = default;

      private:
        /**
         * Universally-Unique Identifier of the plugin that manufactured this instance.
         */
        // plugin::PluginUUID uuid;
      };
    }
  }
}



#endif
