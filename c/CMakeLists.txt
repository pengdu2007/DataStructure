# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.13)
# Set the project name
project(DataStructure)

set(CMAKE_C_STANDARD 99)

# Add an executable
# add_executable(main ./LinearList/sequential.c)
add_executable(main ./Tree/binary_tree.c)