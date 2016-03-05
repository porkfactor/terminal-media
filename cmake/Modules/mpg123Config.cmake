#----mpg123_PARAMETERS----#
set(mpg123_FOUND TRUE)

add_library(libmpg123 SHARED IMPORTED)

if(WIN32)
  set_target_properties(
    libmpg123
    PROPERTIES
    IMPORTED_LOCATION mpg12332.lib
  )
else()
  set(mpg123_include_dir ${MPG123_HOME}/include)
 
  set_target_properties(
    libmpg123
  )
endif()

#----mpg123_PARAMETERS----#
