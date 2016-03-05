#ifndef TERMINAL_MEDIA_IPLAYABLE_HPP_
#define TERMINAL_MEDIA_IPLAYABLE_HPP_

namespace terminal {
  namespace media {
    namespace model {
      class IPlayable {
      public:
        virtual ~IPlayable() = default;

        virtual void Play() = 0;
        virtual void Stop() = 0;
        virtual void Pause() = 0;
        virtual void Resume() = 0;

      private:
      };
    }
  }
}



#endif
