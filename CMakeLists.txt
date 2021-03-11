cmake_minimum_required(VERSION 3.12)
project(hw1 C CXX)


set(CMAKE_C_STANDARD 11)

set(CMAKE_C_COMPILER "gcc-10")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-omit-frame-pointer -g -fsanitize=address,leak,undefined")

add_executable(hw1 main.c include/algorithm.h src/algorithm.c)

enable_testing()

add_subdirectory(test)

