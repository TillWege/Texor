cmake_minimum_required(VERSION 3.27)
project(Texor)

set(CMAKE_CXX_STANDARD 20)

add_executable(Texor src/main.cpp)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(Texor PRIVATE raylib)
