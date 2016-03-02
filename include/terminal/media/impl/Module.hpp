#ifndef TERMINAL_MEDIA_MODULE_HPP_
#define TERMINAL_MEDIA_MODULE_HPP_

#include <terminal/media/Media.hpp>
#include <memory>
#include <functional>
#include <cstdint>

namespace terminal {
  namespace media {
    class Module {
    public:
      typedef uint32_t magic_type;
      typedef uint32_t capabilities_type;

      static const magic_type INVALID_MAGIC = ~0U;

      Module(string const &path);

      magic_type getMagic() const;
      capabilities_type getCapabilities() const;

      template<class T>
      std::function<T> getMethod(string const &functionName) {
        return reinterpret_cast<T *>(getSymbol(functionName));
      }

    protected:
      void *getSymbol(string const &symbolName);

    private:
      std::unique_ptr<void, std::function<int (void *)>> dl_handle_;
    };
  }
}



#endif
