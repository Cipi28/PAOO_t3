cmake_minimum_required(VERSION 3.10)
project(proj_PAOO)

set(HEADERS User.h)

set(SOURCES User.cpp)

add_library(myUser User.h User.cpp)

target_include_directories(myUser PUBLIC ${CMAKE_SOURCE_DIR}/User_lib/include)
