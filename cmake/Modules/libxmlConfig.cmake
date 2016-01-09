#----libxml2_PARAMETERS----#
ADD_LIBRARY(libxml2 SHARED IMPORTED)

IF(APPLE)
  MESSAGE(STATUS "COCK")

  FIND_PATH(libxml2_include_dir 
    libxml/tree.h
    PATHS 
    ${_CMAKE_OSX_SYSROOT_PATH}
    PATH_SUFFIXES libxml2
  )

  MESSAGE(STATUS "${_CMAKE_OSX_SYSROOT_PATH}")
  MESSAGE(STATUS "${libxml2_include_dir}")
ENDIF()

IF(WIN32)
  set_target_properties(
    libxml2
    PROPERTIES
    IMPORTED_LOCATION libxml32.lib
  )
ELSE()
#  SET(libxml_include_dir ${LIBXML_HOME}/include)
# 
#  set_target_properties(
#    libxml2
#  )
ENDIF()

#----libxml_PARAMETERS----#
