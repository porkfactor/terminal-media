#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    class ISerializer {
    public:
    private:
    };

    class ISerializable {
    public:
      virtual ~ISerializable() = default;

      virtual void Serialize(std::shared_ptr<ISerializer>) = 0;

    private:
    };

    class IAttribute : public ISerializable {
    public:
      IAttribute(string const &);
      virtual ~IAttribute() = default;

      string const &GetName() const;

    private:
      string name_;
    };

    class StringAttribute : public IAttribute {

      virtual void Serialize(std::shared_ptr<ISerializer>);

    private:
      string value_;
    };

    class Profile {
    public:
      Profile();


    private:
    };

    class MediaSourceDescriptor {
    public:
    private:
      std::vector<IAttribute> attributes_;
    };



    Profile::Profile() {

    }
  }
}
