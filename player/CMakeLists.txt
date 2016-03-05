project(player)

include_directories(
  ${terminal-media_SOURCE_DIR}/include
)

add_executable(player
  model/AbstractAlbum.cpp
  model/AbstractArtist.cpp
  model/AbstractAudioResource.cpp
  model/AbstractLibrary.cpp
  model/AbstractMediaResource.cpp
  system/MediaPlayer.cpp
  system/Module.cpp
  system/Plugin.cpp
  system/PluginManager.cpp
  system/PluginRegistrar.cpp
  main.cpp
)

target_link_libraries(player
  libterminal-core
  dl
)

