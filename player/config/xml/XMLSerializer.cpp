#include <terminal/media/config/XMLSerializer.hpp>
#include <libxml/xmlwriter.h>

namespace terminal {
  namespace media {
    namespace config {
      struct XMLSerializer::impl {
        impl(string const &path) :
          xmlWriter_(
            ::xmlNewTextWriterFilename(reinterpret_cast<char const *>(path.c_str()), 0),
            ::xmlFreeTextWriter)
        {
        }

        std::unique_ptr<::xmlTextWriter, void (*)(::xmlTextWriterPtr)> xmlWriter_;
      };

      XMLSerializer::XMLSerializer(string const &path) :
        pimpl_(new impl(path))
      {
      }

      void XMLSerializer::SerializeStartObject(string const &name) {
        ::xmlTextWriterStartElement(
            pimpl_->xmlWriter_.get(),
            reinterpret_cast<xmlChar const *>(name.c_str())
        );
      }

      void XMLSerializer::SerializeEndObject() {
        ::xmlTextWriterEndElement(pimpl_->xmlWriter_.get());
      }

      void XMLSerializer::SerializeString(string const &name, string const &value) {
        ::xmlTextWriterWriteElement(
            pimpl_->xmlWriter_.get(),
            reinterpret_cast<xmlChar *>(name.c_str()),
            reinterpret_cast<xmlChar *>(value.c_str()));
      }

      void XMLSerializer::SerializeInt32(string const &name, int32_t value) {
        SerializeString(name, std::to_wstring(value));
      }

      void XMLSerializer::SerializeInt64(string const &name, int64_t value) {
        SerializeString(name, std::to_wstring(value));
      }

      void XMLSerializer::SerializeFloat32(string const &name, float value) {
        SerializeString(name, std::to_wstring(value));
      }

      void XMLSerializer::SerializeFloat64(string const &name, double value) {
        SerializeString(name, std::to_wstring(value));
      }
    }
  }
}
