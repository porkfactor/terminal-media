#ifndef INCLUDE_TERMINAL_MEDIA_LOGGER_HPP_
#define INCLUDE_TERMINAL_MEDIA_LOGGER_HPP_

#include <terminal/media/api/Types.hpp>

namespace terminal {
  namespace media {
    class LogDevice {
    public:
      virtual ~LogDevice() = default;
    };

    class Logger {
    public:
      typedef enum {
        INFO                           = (0x1 << 0),
        ERROR                          = (0x1 << 1),
        WARNING                        = (0x1 << 2)
      } severity_type;

      Logger();

      void Log(severity_type, api::string const &);

      static Logger &instance();

    private:
      static Logger instance_;
    };

    static inline void Log(Logger::severity_type severity, api::string const &format) {
      Logger::instance().Log(severity, format);
    }
  }
}

#endif
