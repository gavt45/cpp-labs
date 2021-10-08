cmake_minimum_required(VERSION 3.19)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -pedantic)

# googletest
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
##

add_executable(cpp_labs_1)

add_executable(cpp_labs_2)
add_executable(cpp_labs_2_test)

add_subdirectory(lab1)
add_subdirectory(lab2)
