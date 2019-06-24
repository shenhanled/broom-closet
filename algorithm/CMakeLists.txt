cmake_minimum_required(VERSION 3.8)

project(broom-closet)
add_compile_options(-std=c++11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(bfprt
        ${PROJECT_SOURCE_DIR}/src/cpp/bfprt.cpp)
add_executable(quick_sort
        ${PROJECT_SOURCE_DIR}/src/cpp/quick_sort.cpp)