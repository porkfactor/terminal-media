project(ao_plugin)

add_definitions(-DDLL__TERMINAL_MEDIA)

include_directories(
  ${terminal-media_SOURCE_DIR}/include
)

add_library(modao SHARED
  AOPlayer.cpp
  Plugin.cpp
)

target_link_libraries(modao
)

set_target_properties(modao PROPERTIES
  VERSION 1.0.0
  SOVERSION 1
)
