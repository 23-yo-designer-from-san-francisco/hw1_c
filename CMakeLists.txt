cmake_minimum_required(VERSION 3.14)
project(untitled1 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER "gcc-10")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-omit-frame-pointer -g -fsanitize=address,leak,undefined")

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
message(${GTEST_LIBRARIES})

add_executable(untitled1 main.c include/algorithm.h src/algorithm.c)
add_executable(tests test/algorithm.cpp)

target_link_libraries(untitled1 -lpthread ${GTEST_LIBRARIES})
target_link_libraries(tests -lpthread ${GTEST_LIBRARIES})

add_test(
    NAME tests
    COMMAND tests
)
