

namespace terminal {
  namespace media {
    namespace config {
      StringAttribute::StringAttribute(string const &name, string const &value) :
        IAttribute(name),
        value_(value)
      {
      }

      StringAttribute::Serialize(std::shared_ptr<ISerializer> &serializer) {
        serializer::SerializeString(GetName(), GetValue());
      }
    }
  }
}
