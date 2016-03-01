#include <terminal/media/player/MediaPlayer.hpp>
#include <terminal/core/Logger.hpp>
#include <clocale>
#include <locale>

namespace media = terminal::media;

int main(int argc, char **argv) {
  media::MediaPlayer mediaPlayer;
  std::setlocale(std::locale::all, "");

  media::Log(media::Logger::INFO, std::string(u8"starting"));

  mediaPlayer.Execute();

  return 0;
}
