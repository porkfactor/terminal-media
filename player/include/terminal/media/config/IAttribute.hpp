#ifndef TERMINAL_MEDIA_CONFIG_IATTRIBUTE_HPP_
#define TERMINAL_MEDIA_CONFIG_IATTRIBUTE_HPP_

namespace terminal {
  namespace media {
    namespace config {
      class IAttribute : public ISerializable {
      public:
        IAttribute(string const &);
        virtual ~IAttribute() = default;

      private:
        string name_;
      };
    }
  }
}

#endif
