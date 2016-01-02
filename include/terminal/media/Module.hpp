#ifndef TERMINAL_MEDIA_MODULE_HPP_
#define TERMINAL_MEDIA_MODULE_HPP_

#include <terminal/media/Media.hpp>
#include <cstdint>

namespace terminal {
  namespace media {
    class Module {
    public:
      typedef uint32_t magic_type;
      typedef uint32_t capabilities_type;

      static const magic_type INVALID_MAGIC = ~0U;

      Module(string const &path);
      ~Module();

      magic_type GetMagic() const;
      capabilities_type GetCapabilities() const;

    private:
      struct impl;
      std::unique_ptr<impl> pimpl_;
    };
  }
}



#endif
