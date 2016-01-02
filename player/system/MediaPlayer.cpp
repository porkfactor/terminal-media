#include <terminal/media/MediaPlayer.hpp>
#include <terminal/media/PluginManager.hpp>
#include <unistd.h>

namespace terminal {
  namespace media {
    MediaPlayer::MediaPlayer() :
      workingDirectory_(""),
      pluginDirectory_("/Users/dsmith/objects/install/lib")
    {
    }

    void MediaPlayer::Execute() {
      PluginManager pluginManager;

      pluginManager.ScanDirectory(pluginDirectory_);
    }
  }
}



