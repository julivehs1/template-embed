cmake_minimum_required(VERSION 3.23)
project(template_embed)

set(CMAKE_CXX_STANDARD 17)
message(${CMAKE_BINARY_DIR})
add_executable(template_embed main.cpp stringify.cpp stringify.h)
