#ifndef TERMINAL_MEDIA_PLUGIN_HPP_
#define TERMINAL_MEDIA_PLUGIN_HPP_

#include <terminal/media/Media.hpp>

namespace terminal {
  namespace media {
    class Plugin {
    public:
      Plugin(string const &);

    private:
      struct impl;
      std::unique_ptr<impl> pimpl_;
    };
  }
}



#endif
