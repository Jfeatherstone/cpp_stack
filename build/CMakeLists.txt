cmake_minimum_required(VERSION 3.14.5)

# Compile according to C++17 standard
set(CMAKE_CXX_STANDARD 17)

project(stack)

file(GLOB_RECURSE SRC src/*.cpp)

include_directories(include/)

add_executable(${PROJECT_NAME} ${SRC})