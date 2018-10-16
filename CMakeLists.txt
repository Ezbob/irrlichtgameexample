cmake_minimum_required(VERSION 3.0)
project(gamec++)

# setting variable BINARY
set(BINARY example)

# we can put custom Find<library>.cmake files here
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# globbing to find the sources
file(GLOB_RECURSE sources src/main/*.cpp src/main/*.hpp)
# and test sources
file(GLOB_RECURSE sources_test src/test/*.cpp)

# cmake needs to find the irrlicht lib. There are some predefined Find files which cmake uses
# but sometimes we have to make our own
find_package(irrlicht REQUIRED)

# We need a binary from sources
add_executable(${BINARY} ${sources})

# compiler flags
target_compile_options(${BINARY} PUBLIC -std=c++11 -Wall -Wextra -pedantic)

# -I <dirname> in g++ terms. namely which directories we should look for headers in
target_include_directories(${BINARY} PUBLIC src/main)

# we need to link the libraries into our executable
target_link_libraries(${BINARY} ${irrlicht_LIBRARIES})

