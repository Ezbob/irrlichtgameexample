cmake_minimum_required(VERSION 3.0)
project(gamec++)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

file(GLOB_RECURSE sources src/main/*.cpp src/main/*.hpp)
file(GLOB_RECURSE sources_test src/test/*.cpp)
file(GLOB_RECURSE data resources/*)

find_package(irrlicht REQUIRED)

add_executable(example ${sources} ${data})

target_compile_options(example PUBLIC -std=c++11 -Wall -Wextra -pedantic)

target_include_directories(example PUBLIC src/main)

file(COPY ${data} DESTINATION resources)

target_link_libraries(example ${irrlicht_LIBRARIES})

