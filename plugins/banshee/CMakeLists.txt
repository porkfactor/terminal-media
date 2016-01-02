project(banshee_plugin)

add_definitions(-DDLL__TERMINAL_MEDIA)

include_directories(
  ${terminal-media_SOURCE_DIR}/include
)

add_library(modbanshee SHARED
  Library.cpp
  Reader.cpp
)

target_link_libraries(modbanshee
  sqlite3
)

