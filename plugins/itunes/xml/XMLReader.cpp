#include <libxml/tree.h>
#include <libxml/xmlstring.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <terminal/media/Media.hpp>
#include <vector>

namespace terminal {
  namespace media {
    namespace itunes {
      namespace xml {
        static inline string xmlString(::xmlChar const *c, int len) {
          return string(reinterpret_cast<string::value_type const *>(c), len);
        }

        static inline string xmlString(::xmlChar const *c) {
          return string(reinterpret_cast<string::value_type const *>(c));
        }

        class SaxParser {
        public:
          SaxParser();
          virtual ~SaxParser();

          void OpenFile(string const &);

          virtual void StartDocument();
          virtual void EndDocument();
          virtual void StartElement(string const &name, std::vector<string> const &attributes);
          virtual void EndElement(string const &name);
          virtual void StartElementNs(string const &name, string const &prefix, string const &URI, std::vector<string> const &, std::vector<string> const &);
          virtual void EndElementNs(string const &name, string const &prefix, string const &URI);
          virtual void Characters(string const &);
          virtual void Comment(string const &);
          virtual void CDataBlock(string const &);
          virtual void IgnorableWhitespace(string const &);

        private:
          static void ProcessingInstruction_(void * ctx, ::xmlChar const * target, ::xmlChar const * data);

          static void StartDocument_(void * );
          static void EndDocument_(void *);
          static void StartElement_(void *, ::xmlChar const *, ::xmlChar const **);
          static void EndElement_(void *, ::xmlChar const *);
          static void StartElementNs_(void *, ::xmlChar const *, ::xmlChar const *, ::xmlChar const *, int, ::xmlChar const **, int, int, ::xmlChar const **);
          static void EndElementNs_(void *, ::xmlChar const *, ::xmlChar const *, ::xmlChar const *);
          static void Characters_(void *, ::xmlChar const *, int);
          static void CDataBlock_(void *, ::xmlChar const *, int);
          static void Comment_(void *ctx, ::xmlChar const *);
          static void IgnorableWhitespace_(void *ctx, ::xmlChar const *, int);

          static void FatalError_(void * ctx, const char * msg, ...);
          static void Warning_(void * ctx, const char * msg, ...);
          static void Error_(void * ctx, const char * msg, ...);

          ::xmlSAXHandler handler_;
        };

        SaxParser::SaxParser() {
          handler_.cdataBlock = CDataBlock_;
          handler_.characters = Characters_;
          handler_.comment = Comment_;
          handler_.endDocument = EndDocument_;
          handler_.endElement = EndElement_;
          handler_.endElementNs = EndElementNs_;
          handler_.ignorableWhitespace = IgnorableWhitespace_;
          handler_.processingInstruction = ProcessingInstruction_;
          handler_.startDocument = StartDocument_;
          handler_.startElement = StartElement_;
          handler_.startElementNs = StartElementNs_;

          handler_.fatalError = FatalError_;
          handler_.error = Error_;
          handler_.warning = Warning_;
        }

        SaxParser::~SaxParser() {
        }

        void SaxParser::OpenFile(string const &path) {
          xmlParserCtxt* parserContext;

          if((parserContext = ::xmlCreateFileParserCtxt(path.c_str())) != nullptr) {

            parserContext->sax = &handler_;
            parserContext->userData = this;

            ::xmlFreeParserCtxt(parserContext);
          }
        }

        void SaxParser::StartDocument_(void *ctx) {
          static_cast<SaxParser *>(ctx)->StartDocument();
        }

        void SaxParser::StartDocument() {
        }

        void SaxParser::EndDocument_(void *ctx) {
          static_cast<SaxParser *>(ctx)->EndDocument();
        }

        void SaxParser::EndDocument() {
        }

        void SaxParser::StartElement_(void *ctx, ::xmlChar const *name, ::xmlChar const **attrs) {
          std::vector<string> attributes;

          for(size_t i = 0; attrs[i]; i++) {
            attributes.push_back(xmlString(attrs[i]));
          }

          static_cast<SaxParser *>(ctx)->StartElement(xmlString(name), attributes);
        }

        void SaxParser::StartElement(string const &, std::vector<string> const &) {
        }

        void SaxParser::EndElement_(void *ctx, ::xmlChar const *name) {
          static_cast<SaxParser *>(ctx)->EndElement(xmlString(name));
        }

        void SaxParser::EndElement(string const &) {
        }

        void SaxParser::StartElementNs_(void *ctx, ::xmlChar const *localname, ::xmlChar const *prefix, ::xmlChar const *URI, int nb_namespaces, ::xmlChar const **xmlNamespaces, int nb_attributes, int nb_defaulted, ::xmlChar const **xmlAttributes) {
          std::vector<string> attributes;
          std::vector<string> namespaces;

          for(int i = 0; i < nb_namespaces; i++) {
            namespaces.push_back(xmlString(xmlNamespaces[i]));
          }

          for(int i = 0; i < nb_attributes; i++) {
            attributes.push_back(xmlString(xmlAttributes[i]));
          }

          static_cast<SaxParser *>(ctx)->StartElementNs(xmlString(localname), xmlString(prefix), xmlString(URI), namespaces, attributes);
        }

        void SaxParser::StartElementNs(string const &name, string const &prefix, string const &URI, std::vector<string> const &namespaces, std::vector<string> const &attributes) {
        }

        void SaxParser::EndElementNs_(void *ctx, ::xmlChar const *name, ::xmlChar const *prefix, ::xmlChar const *URI) {
          static_cast<SaxParser *>(ctx)->EndElementNs(xmlString(name), xmlString(prefix), xmlString(URI));
        }

        void SaxParser::EndElementNs(string const &name, string const &prefix, string const &URI) {
        }

        void SaxParser::Characters_(void *ctx, ::xmlChar const *c, int len) {
          static_cast<SaxParser *>(ctx)->Characters(xmlString(c, len));
        }

        void SaxParser::Characters(string const &) {
        }

        void SaxParser::CDataBlock_(void *ctx, ::xmlChar const *value, int len) {
          static_cast<SaxParser *>(ctx)->CDataBlock(xmlString(value, len));
        }

        void SaxParser::CDataBlock(string const &) {
        }

        void SaxParser::Comment_(void *ctx, ::xmlChar const *comment) {
          static_cast<SaxParser *>(ctx)->Comment(xmlString(comment));
        }

        void SaxParser::Comment(string const &) {
        }

        void SaxParser::IgnorableWhitespace_(void *ctx, ::xmlChar const *value, int len) {
          static_cast<SaxParser *>(ctx)->IgnorableWhitespace(xmlString(value, len));
        }

        void SaxParser::IgnorableWhitespace(string const &) {
        }

        void SaxParser::ProcessingInstruction_(void *ctx, ::xmlChar const *target, ::xmlChar const *data) {
        }

        void SaxParser::Error_(void *ctx, char const *msg, ...) {
        }

        void SaxParser::Warning_(void *ctx, char const *msg, ...) {
        }

        void SaxParser::FatalError_(void *ctx, char const *msg, ...) {

        }
      }

      class LibraryLoader {
      public:
        void doing();

      private:

      };

      void LibraryLoader::doing() {

      }
    }
  }
}

