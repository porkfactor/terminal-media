#----sqlite_PARAMETERS----#
set(sqlite_FOUND TRUE)

add_library(libsqlite SHARED IMPORTED)

if(WIN32)
  set_target_properties(
    libsqlite
    PROPERTIES
    IMPORTED_LOCATION sqlite32.lib
  )

  set_target_properties(
    libsqliteinst
    PROPERTIES
    IMPORTED_LOCATION advapi32.lib
  )
else()
  set(sqlite_include_dir ${SQLITE_HOME}/include)
 
  set_target_properties(
    libsqlite3
  )
endif()

#----sqlite_PARAMETERS----#
