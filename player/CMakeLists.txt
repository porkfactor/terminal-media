project(terminal-media)

include_directories(
  ${terminal-media_SOURCE_DIR}/include
)

add_executable(player
  system/Logger.cpp
  import/banshee.cpp
  model/Album.cpp
  model/Artist.cpp
  model/AudioResource.cpp
  model/MediaResource.cpp
  main.cpp
)

target_link_libraries(player
  sqlite3
)

