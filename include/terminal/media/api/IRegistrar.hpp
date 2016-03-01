#ifndef TERMINAL_MEDIA_PLUGIN_IREGISTRAR_HPP_
#define TERMINAL_MEDIA_PLUGIN_IREGISTRAR_HPP_

#include <terminal/media/api/Types.hpp>

namespace terminal {
  namespace media {
    namespace api {
      class IPlugin;
      class IExtensionFactory;

      class IRegistrar {
      public:
        virtual ~IRegistrar() = default;

        virtual void registerPlugin(IPlugin *plugin) = 0;
        virtual void registerExtension(IExtensionFactory *extension) = 0;

      private:
      };
    }
  }
}

#endif
