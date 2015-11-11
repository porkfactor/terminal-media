#include <terminal/media/Media.hpp>
#include <terminal/media/Logger.hpp>

namespace media = terminal::media;

extern void import(void);

int main(int argc, char **argv) {
  media::Log(media::Logger::INFO, L"starting");

  import();

  return 0;
}
