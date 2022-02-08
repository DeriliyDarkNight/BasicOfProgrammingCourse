cmake_minimum_required(VERSION 3.17)
project(untitled6 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled6 main.c)

add_subdirectory(libs)
target_link_libraries(untitled6 data_structures)
target_link_libraries(untitled6 algorithms)