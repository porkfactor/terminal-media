#include <terminal/media/player/MediaPlayer.hpp>
#include <terminal/media/impl/PluginManager.hpp>
#include <terminal/media/impl/PluginRegistrar.hpp>
#include <terminal/media/api/ILibraryManager.hpp>
#include <terminal/core/Logger.hpp>
#include <unistd.h>

namespace terminal {
  namespace media {
    MediaPlayer::MediaPlayer() :
      workingDirectory_(""),
      // TODO: need some super configuration type of jobber to auto-detect stuffs and things
      pluginDirectory_("/home/localadmin/objects/install/lib")
    {
    }

    void MediaPlayer::Execute() {
      std::unique_ptr<api::IRegistrar> registrar { new PluginRegistrar() };
      std::unique_ptr<PluginManager> pluginManager { new PluginManager(registrar.get()) };

      pluginManager->ScanDirectory(pluginDirectory_);

      auto extension = registrar->createExtension(api::ExtensionType::EXTENSION_LIBRARY_MANAGER, u8"banshee");
      api::ILibraryManager *libraryManager = nullptr;

      if((libraryManager = dynamic_cast<decltype(libraryManager)>(extension)) != nullptr) {
        libraryManager->importLibrary( /* TODO: insert configuration */ );
        media::Log(media::Logger::INFO, "loaded an extension!");
      } else {
        media::Log(media::Logger::ERROR, "failed to load extension");
      }

    }
  }
}



