project(mpg123_plugin)

add_definitions(-DDLL__TERMINAL_MEDIA)

include_directories(
  ${terminal-media_SOURCE_DIR}/include
)

add_library(modmpg123 SHARED
  AudioPlayer.cpp
  ExtensionFactory.cpp
  Plugin.cpp
)

target_link_libraries(modmpg123
  mpg123
)

set_target_properties(modmpg123 PROPERTIES
  VERSION 1.0.0
  SOVERSION 1
)
