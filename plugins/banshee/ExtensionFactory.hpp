#ifndef EXTENSIONFACTORY_HPP_
#define EXTENSIONFACTORY_HPP_

#include <terminal/media/api/IExtensionFactory.hpp>

namespace terminal {
  namespace media {
    namespace api {
      class IExtension;
    }

    namespace banshee {
      class ExtensionFactory : public terminal::media::api::IExtensionFactory {
      public:
        ExtensionFactory(terminal::media::api::IPlugin *);
        ~ExtensionFactory();

        terminal::media::api::ExtensionInfo const *getExtensionInfo() const override;
        terminal::media::api::IExtension *createExtension() override;
        void destroyExtension(terminal::media::api::IExtension *) override;
      };
    }
  }
}

#endif
