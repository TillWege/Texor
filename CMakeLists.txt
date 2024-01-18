cmake_minimum_required(VERSION 3.27)
project(Texor)

set(CMAKE_CXX_STANDARD 20)

add_executable(Texor src/main.cpp
        src/ui/TopBar.cpp
        src/ui/TopBar.h
        src/ui/StatusBar.cpp
        src/ui/StatusBar.h
        src/ui/Editor.cpp
        src/ui/Editor.h
        src/core/File.cpp
        src/core/File.h
        src/core/Logging.h
)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(Texor PRIVATE raylib)
