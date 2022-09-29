cmake_minimum_required(VERSION 3.0.0)

project(NeatString_Project VERSION 1.0.0)

add_subdirectory(NeatString)

add_executable(nsTest
nsTest.c)

target_link_libraries(nsTest NeatString)
