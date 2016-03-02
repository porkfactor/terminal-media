#include <terminal/media/api/IRegistrar.hpp>
#include <terminal/media/api/IPlugin.hpp>
#include <terminal/core/Logger.hpp>
#include "BansheeFactory.hpp"

namespace api = terminal::media::api;

extern "C" void initialize() {
  terminal::media::Log(terminal::media::Logger::INFO, std::string(u8"modbanshee : initialize()"));
}

extern "C" void uninitialize() {
  terminal::media::Log(terminal::media::Logger::INFO, std::string(u8"modbanshee : uninitialize()"));
}

static const api::PluginInfo bansheePlugin = {
  api::Version { 1, 0, 0, 0, },
  api::uuid_type { 0, },
};

extern "C" void registerExtensions(api::IPlugin *plugin, api::IRegistrar *registrar) {
  terminal::media::Log(terminal::media::Logger::INFO, std::string(u8"modbanshee : registerExtensions()"));
  registrar->registerExtension(new terminal::media::banshee::BansheeFactory(plugin));
}

extern "C" void deregisterExtensions(api::IPlugin *plugin, api::IRegistrar *registrar) {
  terminal::media::Log(terminal::media::Logger::INFO, std::string(u8"modbanshee : deregisterExtensions()"));
}
