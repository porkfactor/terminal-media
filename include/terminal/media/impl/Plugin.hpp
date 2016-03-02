#ifndef TERMINAL_MEDIA_PLUGIN_HPP_
#define TERMINAL_MEDIA_PLUGIN_HPP_

#include <terminal/media/Media.hpp>
#include <terminal/media/pimpl.hpp>
#include <terminal/media/api/IPlugin.hpp>

namespace api = terminal::media::api;

namespace terminal {
  namespace media {

    class Plugin : public api::IPlugin {
    public:
      Plugin(string const &path);
      ~Plugin();

      void initialize() override;
      void uninitialize() override;
      void registerExtensions(api::IRegistrar *) override;
      void deregisterExtensions(api::IRegistrar *) override;

    private:
      struct impl;
      pimpl<impl> pimpl_;
    };
  }
}

#endif
