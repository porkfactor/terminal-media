#include <terminal/core/Logger.hpp>
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

    void Logger::Log(severity_type, api::string const &format) {
      std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      char buf[64];

      std::strftime(buf, sizeof(buf), "%T %Z", std::localtime(&now_c));

      std::cout
        << buf
        << u8" [ LOG ] "
        << format.c_str()
        << std::endl;
    }
  }
}
