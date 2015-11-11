#ifndef INCLUDE_TERMINAL_MEDIA_LOGGER_HPP_
#define INCLUDE_TERMINAL_MEDIA_LOGGER_HPP_

#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    class Logger {
    public:
      typedef enum {
        INFO
      } severity_type;

      Logger();

      void Log(severity_type, string const &);

      static Logger &instance();

    private:
      static Logger instance_;
    };

    static inline void Log(Logger::severity_type severity, string const &format) {
      Logger::instance().Log(severity, format);
    }
  }
}

#endif
