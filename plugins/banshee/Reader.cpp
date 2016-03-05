#include "Reader.hpp"
#include "model/banshee/Artist.hpp"
#include "model/banshee/AudioResource.hpp"
#include "model/banshee/Album.hpp"
#include <terminal/core/Logger.hpp>
#include <sqlite3.h>

namespace terminal {
  namespace media {
    namespace banshee {
      static const std::string sql_query_artists { "SELECT ca.ArtistID, ca.Name FROM CoreArtists ca" };
      static const std::string sql_query_albums_by_artist { "SELECT ca.AlbumID, ca.Title FROM CoreAlbums ca WHERE ca.ArtistID = ?1" };
      static const std::string sql_query_tracks_by_album { "SELECT ct.TrackID, ct.Title, ct.Uri FROM CoreTracks ct WHERE ct.AlbumID = ?1" };

      struct Reader::impl {
        sqlite3 *handle = nullptr;
      };

      Reader::Reader(terminal::media::api::string const &path) :
        pimpl_{}
      {
        sqlite3_open(path.c_str(), &pimpl_->handle);
      }

      void Reader::loadAlbum(terminal::media::banshee::Album *album) {
        sqlite3_stmt *stmt{nullptr};
        int albumId{album->getId()};
        int result{0};

        if((result = sqlite3_prepare_v2(
            pimpl_->handle,
            sql_query_tracks_by_album.c_str(),
            sql_query_tracks_by_album.length(),
            &stmt,
            0)) == SQLITE_OK) {
          if((result = sqlite3_bind_int(stmt, 1, albumId)) == SQLITE_OK) {

          } else {
            terminal::media::Log(terminal::media::Logger::INFO, sqlite3_errstr(result));
          }

          while((result = sqlite3_step(stmt)) == SQLITE_ROW) {
            int albumId = sqlite3_column_int(stmt, 0);
            std::string trackName{reinterpret_cast<char const *>(sqlite3_column_text(stmt, 1))};
            std::string uri{reinterpret_cast<char const *>(sqlite3_column_text(stmt, 2))};

            terminal::media::Log(terminal::media::Logger::INFO, trackName);
            terminal::media::Log(terminal::media::Logger::INFO, uri);

            banshee::AudioResource *track(new banshee::AudioResource(album, trackName, uri));
          }

          sqlite3_finalize(stmt);
        } else {
          terminal::media::Log(terminal::media::Logger::ERROR, sqlite3_errstr(result));
        }
      }

      void Reader::loadArtist(terminal::media::banshee::Artist *artist) {
        sqlite3_stmt *stmt{nullptr};
        int artistId{artist->getId()};
        int result{0};

        if((result = sqlite3_prepare_v2(
            pimpl_->handle,
            sql_query_albums_by_artist.c_str(),
            sql_query_albums_by_artist.length(),
            &stmt,
            0)) == SQLITE_OK) {
          if((result = sqlite3_bind_int(stmt, 1, artistId)) == SQLITE_OK) {

          } else {
            terminal::media::Log(terminal::media::Logger::INFO, sqlite3_errstr(result));
          }

          while((result = sqlite3_step(stmt)) == SQLITE_ROW) {
            int albumId = sqlite3_column_int(stmt, 0);
            std::string albumName{reinterpret_cast<char const *>(sqlite3_column_text(stmt, 1))};

            terminal::media::Log(terminal::media::Logger::INFO, albumName);

            banshee::Album *album{new banshee::Album(artist, albumName, albumId)};
            loadAlbum(album);
          }

          sqlite3_finalize(stmt);
        } else {
          terminal::media::Log(terminal::media::Logger::ERROR, sqlite3_errstr(result));
        }
      }

      terminal::media::banshee::Library *Reader::loadLibrary(void) {
        terminal::media::banshee::Library *library{nullptr};
        sqlite3_stmt *stmt{nullptr};
        int result{0};

        if((result = sqlite3_prepare_v2(pimpl_->handle, sql_query_artists.c_str(), sql_query_artists.length(), &stmt, 0)) == SQLITE_OK) {
          while((result = sqlite3_step(stmt)) == SQLITE_ROW) {
            int artistId = sqlite3_column_int(stmt, 0);
            std::string artistName{reinterpret_cast<char const *>(sqlite3_column_text(stmt, 1))};

            banshee::Artist *artist{new banshee::Artist{library, artistName, artistId}};

            terminal::media::Log(terminal::media::Logger::INFO, artistName);

            loadArtist(artist);
          }

          sqlite3_finalize(stmt);
        } else {
          terminal::media::Log(terminal::media::Logger::ERROR, sqlite3_errstr(result));
        }

        return library;
      }
    }
  }
}
