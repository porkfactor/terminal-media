#ifndef INCLUDE_TERMINAL_MEDIA_MEDIA_HPP_
#define INCLUDE_TERMINAL_MEDIA_MEDIA_HPP_

#include <string>
#include <memory>

namespace terminal {
  namespace media {
    class Album;
    class Artist;
    class AudioResource;

    typedef std::wstring string;

    typedef std::shared_ptr<Album> album_ptr;
    typedef std::shared_ptr<Album const> album_const_ptr;
    typedef std::weak_ptr<Album> album_wptr;
    typedef std::weak_ptr<Album const> album_const_wptr;
    typedef std::shared_ptr<Artist> artist_ptr;
    typedef std::shared_ptr<Artist const> artist_const_ptr;
    typedef std::weak_ptr<Artist> artist_wptr;
    typedef std::weak_ptr<Artist const> artist_const_wptr;
    typedef std::shared_ptr<AudioResource> audio_ptr;
    typedef std::shared_ptr<AudioResource const> audio_const_ptr;
    typedef std::weak_ptr<AudioResource> audio_wptr;
    typedef std::weak_ptr<AudioResource const> audio_const_wptr;

  }
}

#endif
