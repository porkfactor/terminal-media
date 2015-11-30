project(terminal-media)

include_directories(
  ${terminal-media_SOURCE_DIR}/include
)

add_executable(player
  system/Logger.cpp
  model/Album.cpp
  model/Artist.cpp
  model/AudioResource.cpp
  model/Library.cpp
  model/MediaResource.cpp
  main.cpp
)

add_subdirectory(plugins)

target_link_libraries(player
)

