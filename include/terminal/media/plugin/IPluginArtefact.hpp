#ifndef TERMINAL_MEDIA_PLUGIN_IPLUGINARTEFACT_HPP_
#define TERMINAL_MEDIA_PLUGIN_IPLUGINARTEFACT_HPP_

namespace terminal {
  namespace media {
    namespace plugin {
      class IPluginArtefact {
      public:
        virtual ~IPluginArtefact() = default;

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
