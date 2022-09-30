#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "NeatString" for configuration "Debug"
set_property(TARGET NeatString APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(NeatString PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "/usr/local/lib/NeatString/libNeatString.a"
  )

list(APPEND _cmake_import_check_targets NeatString )
list(APPEND _cmake_import_check_files_for_NeatString "/usr/local/lib/NeatString/libNeatString.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
