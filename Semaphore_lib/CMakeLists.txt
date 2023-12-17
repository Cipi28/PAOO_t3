cmake_minimum_required(VERSION 3.10)
project(proj_PAOO)

add_library(mySemaphore Semaphore.h Semaphore.cpp)

target_include_directories(mySemaphore PUBLIC ${CMAKE_SOURCE_DIR}/Semaphore_lib/include)