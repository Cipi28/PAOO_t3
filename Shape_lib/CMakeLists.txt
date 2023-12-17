cmake_minimum_required(VERSION 3.10)
project(proj_PAOO)

set(HEADERS Shape.h)

add_library(myShape Shape.h Shape.cpp)

target_include_directories(myShape PUBLIC ${CMAKE_SOURCE_DIR}/Shape_lib/include)