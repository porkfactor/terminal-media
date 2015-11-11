#include <terminal/media/Media.hpp>
#include <terminal/media/Logger.hpp>
#include <sqlite3.h>

#define ARTIST_QUERY "SELECT ca.* FROM CoreArtists ca"

namespace tt = terminal::media;

class Banshee {
  void import(void);
  void import_database(terminal::media::string const &);
  void import_artist(terminal::media::string const &);
  void import_album(terminal::media::string const &);

  sqlite3 *handle;
};



void Banshee::import_database(tt::string const &database) {
  if(sqlite3_open(reinterpret_cast<char const *>(database.c_str()), &handle) == SQLITE_OK) {
    tt::Log(tt::Logger::INFO, L"opened file : " + database);

    sqlite3_stmt *stmt_handle;

    if(sqlite3_prepare_v2(handle, ARTIST_QUERY, -1, &stmt_handle, 0) == SQLITE_OK) {
      sqlite3_finalize(stmt_handle);
    }

    sqlite3_close(handle);
  } else {
    tt::Log(tt::Logger::INFO, L"failed to open file : " + database);
  }
}

void Banshee::import() {
  tt::string path { L"~/.config/banshee-1/banshee.db" };

  import_database(path);
}

