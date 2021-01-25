# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.13)
# Set the project name
project(Tree)

set(CMAKE_C_STANDARD 99)
set(SRC_LIST binary_tree.c)

# Add an executable
add_executable(main ${SRC_LIST})