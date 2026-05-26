cmake_minimum_required(VERSION 4.2)
project(idx)

set(CMAKE_CXX_STANDARD 26)

add_executable(idx main.cpp
        io.cpp
        io.h
        indexer.cpp
        indexer.h)

target_compile_options(idx PRIVATE -Werror -Wall -Wextra -Wconversion -Wsign-conversion)