#ifndef TERMINAL_MEDIA_PIMPL_HPP_
#define TERMINAL_MEDIA_PIMPL_HPP_

#include <memory>
#include <utility>

template<typename T>
class pimpl {
public:
  pimpl() : ptr_ { new T { } } { };
  ~pimpl() { };
  template<typename ...Args>
  pimpl(Args&& ...args) : ptr_ { new T { std::forward<Args>(args)... } } { };
  T *operator->() { return ptr_.get(); };
  T &operator*() { return *ptr_.get(); };

private:
  std::unique_ptr<T> ptr_;
};

#endif
