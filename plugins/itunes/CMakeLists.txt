project(itunes-plugin)

add_definitions(-DDLL__TERMINAL_MEDIA)

include_directories(
  ${terminal-media_SOURCE_DIR}/include
)

add_library(moditunes SHARED
  Plugin.cpp
)

target_link_libraries(moditunes
  xml2
)

set_target_properties(moditunes PROPERTIES
  VERSION 1.0.0
  SOVERSION 1
)
