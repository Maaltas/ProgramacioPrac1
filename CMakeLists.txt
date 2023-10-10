cmake_minimum_required(VERSION 3.26)
project(Practica1)

set(CMAKE_CXX_STANDARD 17)

include_directories(Headers/include)

add_executable(Practica1
        Sources/main.cpp
        Sources/src/MyEnum.cpp
        Sources/src/Position.cpp
        Sources/src/Snake.cpp
        Sources/src/Taulell.cpp)