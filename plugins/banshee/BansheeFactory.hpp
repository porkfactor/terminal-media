#ifndef BANSHEEFACTORY_HPP_
#define BANSHEEFACTORY_HPP_

#include <terminal/media/api/IExtensionFactory.hpp>

namespace terminal {
  namespace media {
    namespace api {
      class IExtension;
    }

    namespace banshee {
      class BansheeFactory : public terminal::media::api::IExtensionFactory {
      public:
        BansheeFactory(terminal::media::api::IPlugin *);
        ~BansheeFactory();

        terminal::media::api::ExtensionInfo const *getExtensionInfo() const override;
        terminal::media::api::IExtension *createExtension() override;
        void destroyExtension(terminal::media::api::IExtension *) override;
      };
    }
  }
}

#endif
