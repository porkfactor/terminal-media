################################################
#this part is default Win configuration file
#

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

message(STATUS "Darwin-config loaded")

add_definitions(-std=c++11)
add_definitions(-D_XOPEN_SOURCE_EXTENDED)
