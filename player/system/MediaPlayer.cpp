#include <terminal/media/player/MediaPlayer.hpp>
#include <terminal/media/impl/PluginManager.hpp>
#include "PluginRegistrar.hpp"
#include <unistd.h>

namespace terminal {
  namespace media {
    MediaPlayer::MediaPlayer() :
      workingDirectory_(""),
      pluginDirectory_("/Users/dsmith/objects/install/lib")
    {
    }

    void MediaPlayer::Execute() {
      PluginRegistrar registrar;
      PluginManager pluginManager(&registrar);

      pluginManager.ScanDirectory(pluginDirectory_);
    }
  }
}



