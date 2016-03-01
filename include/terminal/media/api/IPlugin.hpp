#ifndef TERMINAL_MEDIA_PLUGIN_IPLUGIN_HPP_
#define TERMINAL_MEDIA_PLUGIN_IPLUGIN_HPP_

namespace terminal {
  namespace media {
    namespace api {
      class IRegistrar;

      /**
       * Base representation of a Plugin.
       */
      class IPlugin {
      public:
        virtual ~IPlugin() = default;

        virtual void initialize() = 0;
        virtual void uninitialize() = 0;

        virtual void registerExtensions(IRegistrar *) = 0;
        virtual void deregisterExtensions(IRegistrar *) = 0;
      private:
      };
    }
  }
}



#endif
