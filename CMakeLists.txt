cmake_minimum_required(VERSION 2.8.7)
project(terminal-media)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

LIST(APPEND CMAKE_MODULE_PATH 
  ${terminal-media_SOURCE_DIR}/cmake 
  ${terminal-media_SOURCE_DIR}/cmake/Config
)

include(TerminalCommon)
include(Install)

TTUsePackage(libxml)

add_subdirectory(core)
add_subdirectory(player)
add_subdirectory(plugins)
