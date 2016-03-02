project(banshee_plugin)

add_definitions(-DDLL__TERMINAL_MEDIA)

include_directories(
  ${terminal-media_SOURCE_DIR}/include
)

add_library(modbanshee SHARED
  BansheeFactory.cpp
  BansheeLibrary.cpp
  Reader.cpp
  Plugin.cpp
)

target_link_libraries(modbanshee
  libterminal-core
  sqlite3
)

set_target_properties(modbanshee PROPERTIES
  VERSION 1.0.0
  SOVERSION 1
)
