cmake_minimum_required(VERSION 3.0.0)

project(NeatString VERSION 1.0.0)

add_library(NeatString
NeatString.c)

message(${CMAKE_INSTALL_PREFIX})
