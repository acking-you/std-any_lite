cmake_minimum_required(VERSION 3.0.0)
project(any_lite)

set(CMAKE_CXX_STANDARD 11)
include_directories(dependencies/my-logger/include)
add_subdirectory(dependencies/my-logger)

add_executable(any_lite_test test_any.cpp)
target_link_libraries(any_lite_test logger)
