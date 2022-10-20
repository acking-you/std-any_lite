cmake_minimum_required(VERSION 3.0.0)
project(simple_any)

set(CMAKE_CXX_STANDARD 14)
include_directories(dependencies/my-logger/include)
add_subdirectory(dependencies/my-logger)

add_executable(simple_any test_simple_any.cpp)
target_link_libraries(simple_any logger)
