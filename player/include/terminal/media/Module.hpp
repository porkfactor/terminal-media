#ifndef TERMINAL_MEDIA_MODULE_HPP_
#define TERMINAL_MEDIA_MODULE_HPP_

#include <terminal/media/Module.hpp>

namespace terminal {
  namespace media {
    class Module {
    public:
      typedef uint32_t magic_type;
      typedef uint32_t capabilities_type;

      Module(string const &path);

      magic_type GetMagic() const;
      capabilities_type GetCapabilities() const;

    private:
      struct impl;
      std::unique_ptr<impl> pimpl_;
    };
  }
}



#endif
