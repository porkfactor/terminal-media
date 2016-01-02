#ifndef TERMINAL_MEDIA_CONFIG_ISERIALIZER_HPP_
#define TERMINAL_MEDIA_CONFIG_ISERIALIZER_HPP_

namespace terminal {
  namespace media {
    namespace config {
      class ISerializer {
      public:
        virtual ~ISerializer() = default;

        virtual void SerializeAttribute(IAttribute const &);

        virtual void SerializeObject(string const &, IObject const &) = 0;
        virtual void SerializeArray(string const &, IArray const &) = 0;
        virtual void SerializeString(string const &, string const &) = 0;
        virtual void SerializeInt32(string const &, int32_t) = 0;
        virtual void SerializeInt64(string const &, int64_t) = 0;
        virtual void SerializeFloat64(string const &, double) = 0;
        virtual void SerializeFloat32(string const &, float) = 0;

      private:

      };
    }
  }
}
#endif
