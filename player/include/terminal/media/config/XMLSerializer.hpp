#ifndef TERMINAL_MEDIA_CONFIG_XMLSERIALIZER_HPP_
#define TERMINAL_MEDIA_CONFIG_XMLSERIALIZER_HPP_

#include <terminal/media/config/ISerializer.hpp>

namespace terminal {
  namespace media {
    namespace config {
      class XMLSerializer : public ISerializer {
      public:
        XMLSerializer(string const &path);

        void SerializeString(string const &, string const &);
        void SerializeInt32(string const &, int32_t);
        void SerializeInt64(string const &, int64_t);
        void SerializeFloat64(string const &, double);
        void SerializeFloat32(string const &, float);

      private:
        struct impl;
        std::unique_ptr<impl> pimpl_;
      };
    }
  }
}



#endif
