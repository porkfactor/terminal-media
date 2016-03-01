#----libxml2_PARAMETERS----#
ADD_LIBRARY(libxml2 SHARED IMPORTED)

IF(APPLE)
  FIND_PATH(libxml2_include_dir 
    libxml/tree.h
    PATHS 
    ${_CMAKE_OSX_SYSROOT_PATH}
    PATH_SUFFIXES libxml2
  )
ELSEIF(WIN32)
  set_target_properties(
    libxml2
    PROPERTIES
    IMPORTED_LOCATION libxml32.lib
  )
ELSE()
  FIND_PATH(libxml2_include_dir
    libxml/tree.h
    PATH_SUFFIXES libxml2
  )
ENDIF()

#----libxml_PARAMETERS----#
