#include <terminal/media/Logger.hpp>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <ctime>

namespace terminal {
  namespace media {
    Logger Logger::instance_;

    Logger::Logger() {
    }

    Logger &Logger::instance() {
      return instance_;
    }

    void Logger::Log(severity_type, string const &format) {
      std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      char buf[64];

      std::strftime(buf, sizeof(buf), "%c %Z", std::localtime(&now_c));

      std::cout
        << u8"LOG : "
        << buf
        << u8" : " << format.c_str()
        << std::endl;
    }
  }
}
