cmake_minimum_required(VERSION 3.17)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER "gcc-10")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-omit-frame-pointer -g -fsanitize=address,leak,undefined")

add_executable(untitled1 main.c include/algorithm.h src/algorithm.c)