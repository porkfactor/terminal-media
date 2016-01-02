#ifndef TERMINAL_MEDIA_CONFIG_OBJECTATTRIBUTE_HPP_
#define TERMINAL_MEDIA_CONFIG_OBJECTATTRIBUTE_HPP_

namespace terminal {
  namespace media {
    namespace config {
      class ObjectAttribute : public IAttribute {
      public:
        ObjectAttribute(string const &);

      private:
        std::vector<std::unique_ptr<IAttribute>> attributes_;
      };
    }
  }
}

#endif
