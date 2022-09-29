#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "NeatString" for configuration ""
set_property(TARGET NeatString APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(NeatString PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C"
  IMPORTED_LOCATION_NOCONFIG "/usr/local/lib/NeatString/libNeatString.a"
  )

list(APPEND _cmake_import_check_targets NeatString )
list(APPEND _cmake_import_check_files_for_NeatString "/usr/local/lib/NeatString/libNeatString.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
