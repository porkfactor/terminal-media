project(terminal-core)

add_definitions(-DDLL__TERMINAL_MEDIA)

include_directories(
  ${terminal-media_SOURCE_DIR}/include
)

add_library(libterminal-core SHARED
  Logger.cpp
)

target_link_libraries(libterminal-core
)

set_target_properties(libterminal-core PROPERTIES
  VERSION 1.0.0
  SOVERSION 1
)
