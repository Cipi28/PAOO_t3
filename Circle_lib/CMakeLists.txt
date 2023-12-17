cmake_minimum_required(VERSION 3.10)
project(proj_PAOO)

set(HEADERS Circle.h)

set(SOURCES Cirlce.cpp)

add_library(myCircle Circle.h Circle.cpp)

target_include_directories(myCircle PUBLIC ${CMAKE_SOURCE_DIR}/Circle_lib/include)