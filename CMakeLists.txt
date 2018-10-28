cmake_minimum_required(VERSION 3.0)
project(gamec++)

# we can put custom Find<library>.cmake files here
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# cmake needs to find the irrlicht lib. There are some predefined Find files which cmake uses
# but sometimes we have to make our own
find_package(irrlicht REQUIRED)

# setting variable PART1_BIN
set(PART1_BIN example1)

# globbing to find the sources
file(GLOB_RECURSE sources src/p1/*.cpp src/p1/*.hpp)
# and test sources
file(GLOB_RECURSE sources_test src/test/*.cpp)

# We need a binary from sources
add_executable(${PART1_BIN} ${sources})

# compiler flags
target_compile_options(${PART1_BIN} PUBLIC -std=c++11 -Wall -Wextra -pedantic)

# -I <dirname> in g++ terms. namely which directories we should look for headers in
target_include_directories(${PART1_BIN} PUBLIC 
    src/p1
    ${IRRLICHT_INCLUDE_DIR}
)

# we need to link the libraries into our executable
target_link_libraries(${PART1_BIN} ${IRRLICHT_LIBRARY})

#----------------------------------------------------------------------------------

# setting variable PART1_BIN
set(PART2_BIN example2)

# globbing to find the sources
file(GLOB_RECURSE sources src/p2/*.cpp src/p2/*.hpp)
# and test sources
file(GLOB_RECURSE sources_test src/test/*.cpp)

# We need a binary from sources
add_executable(${PART2_BIN} ${sources})

# compiler flags
target_compile_options(${PART2_BIN} PUBLIC -std=c++11 -Wall -Wextra -pedantic)

# -I <dirname> in g++ terms. namely which directories we should look for headers in
target_include_directories(${PART2_BIN} PUBLIC 
    src/p2
    ${IRRLICHT_INCLUDE_DIR}
)

# we need to link the libraries into our executable
target_link_libraries(${PART2_BIN} ${IRRLICHT_LIBRARY})

