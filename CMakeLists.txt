
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(proj_PAOO VERSION 1.0)

add_subdirectory(User_lib)
add_subdirectory(Shape_lib)
add_subdirectory(Circle_lib)
add_subdirectory(Semaphore_lib)

add_executable(exec main.cpp)

target_include_directories(exec PRIVATE User_lib)
target_include_directories(exec PRIVATE Shape_lib)
target_include_directories(exec PRIVATE Circle_lib)
target_include_directories(exec PRIVATE Semaphore_lib)

target_link_libraries(exec PUBLIC myUser myShape myCircle mySemaphore)