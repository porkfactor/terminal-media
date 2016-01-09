project(player)

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
  system/Logger.cpp
  system/MediaPlayer.cpp
  system/Module.cpp
  system/Plugin.cpp
  system/PluginManager.cpp
  main.cpp
)

target_link_libraries(player
  dl
)

