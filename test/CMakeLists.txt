find_package(Threads REQUIRED)

include(ExternalProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/release-1.10.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(gtest source_dir binary_dir)

add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

set_target_properties(libgtest PROPERTIES
"IMPORTED_LOCATION" "${binary_dir}/lib/libgtest.a"
"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

set_target_properties(libgmock PROPERTIES
"IMPORTED_LOCATION" "${binary_dir}/lib/libgmock.a"
"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

include_directories("${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")

ADD_EXECUTABLE(tests algorithm.cpp)

target_link_libraries(
    tests
    libgtest
    libgmock
)

ADD_TEST(
    NAME tests
    COMMAND tests
)