cmake_minimum_required(VERSION 3.14)
project(raytracing)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/google-test)