#----ao_PARAMETERS----#
set(ao_FOUND TRUE)

add_library(libao SHARED IMPORTED)

if(WIN32)
  set_target_properties(
    libao
    PROPERTIES
    IMPORTED_LOCATION ao32.lib
  )

  set_target_properties(
    libaoinst
    PROPERTIES
    IMPORTED_LOCATION advapi32.lib
  )
else()
  set(ao_include_dir ${AO_HOME}/include)
 
  set_target_properties(
    libao
  )
endif()

#----ao_PARAMETERS----#
