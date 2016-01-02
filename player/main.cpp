#include <terminal/media/Media.hpp>
#include <terminal/media/Logger.hpp>
#include <locale>

namespace media = terminal::media;

extern void import(void);

int main(int argc, char **argv) {
  std::setlocale(std::locale::all, "");

  media::Log(media::Logger::INFO, std::string(u8"starting"));

  return 0;
}
