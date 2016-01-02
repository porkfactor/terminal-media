#----libxml_PARAMETERS----#
set(libxml_FOUND TRUE)

add_library(libxml SHARED IMPORTED)

if(WIN32)
  set_target_properties(
    libxml2
    PROPERTIES
    IMPORTED_LOCATION libxml32.lib
  )
else()
  set(libxml_include_dir ${LIBXML_HOME}/include)
 
  set_target_properties(
    libxml2
  )
endif()

#----libxml_PARAMETERS----#
