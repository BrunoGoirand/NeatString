add_library(NeatString
src/NeatString.c)

#target_include_directories(NeatString PUBLIC include)
target_include_directories(NeatString PUBLIC
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/NeatString.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/NeatString)

install(TARGETS NeatString EXPORT nsExport DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/NeatString)

install(EXPORT nsExport FILE NeatString-config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/NeatString)
