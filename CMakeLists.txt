cmake_minimum_required(VERSION 3.27)
project(Texor)

set(CMAKE_CXX_STANDARD 17)

add_executable(Texor main.cpp)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(Texor PRIVATE raylib)
