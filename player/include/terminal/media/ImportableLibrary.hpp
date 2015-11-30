#ifndef INCLUDE_TERMINAL_MEDIA_IMPORTABLELIBRARY_HPP_
#define INCLUDE_TERMINAL_MEDIA_IMPORTABLELIBRARY_HPP_

namespace terminal {
  namespace media {
    class ImportableLibrary {
    public:
      virtual ~ImportableLibrary() = default;

      void open();
      void close();

    private:
    };
  }
}

#endif
