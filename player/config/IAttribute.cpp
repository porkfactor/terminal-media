
namespace terminal {
  namespace media {
    namespace config {
      IAttribute::IAttribute(string const &name) :
        name_(name)
      {
      }

      string const &IAttribute::GetName() const {
        return name_;
      }
    }
  }
}
