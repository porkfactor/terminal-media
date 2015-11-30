#include "Reader.hpp"
#include <sqlite3.h>

namespace terminal {
  namespace media {
    namespace banshee {
      static const std::string sql_query_artists { "SELECT ca.ArtistID, ca.Name FROM CoreArtists ca" };
      static const std::string sql_query_albums_by_artist { "SELECT ca.AlbumID, ca.Name FROM CoreAlbums WHERE ca.ArtistID = :0" };
      static const std::string sql_query_tracks_by_album { "SELECT ct.* FROM CoreTracks WHERE ct.AlbumID = :0" };

      struct Reader::impl {
        sqlite3 *handle = nullptr;
      };

      Reader::Reader(terminal::media::string const &path) :
        pimpl_(new impl())
      {
      }

      void Reader::loadArtist(Library &library, int artistId, std::string const &) {
        sqlite3_stmt *stmt = 0;

        if(sqlite3_prepare_v2(pimpl_->handle, sql_query_albums_by_artist.c_str(), sql_query_albums_by_artist.length(), &stmt, 0) == SQLITE_OK) {
          int result = 0;
          sqlite3_bind_int(stmt, 0, artistId);

          while((result = sqlite3_step(stmt)) == SQLITE_ROW) {
            int albumId = sqlite3_column_int(stmt, 0);

          }

          sqlite3_finalize(stmt);
        }
      }

      void Reader::load(Library &library) {
        sqlite3_stmt *stmt = 0;

        if(sqlite3_prepare_v2(pimpl_->handle, sql_query_artists.c_str(), sql_query_artists.length(), &stmt, 0) == SQLITE_OK) {
          int result = 0;

          while((result = sqlite3_step(stmt)) == SQLITE_ROW) {
            int artistId = sqlite3_column_int(stmt, 0);
            std::string artistName = reinterpret_cast<char const *>(sqlite3_column_text(stmt, 1));

            loadArtist(library, artistId, artistName);
          }

          sqlite3_finalize(stmt);
        }
      }
    }
  }
}
