cmake_minimum_required(VERSION 3.17)

# Sets project name and enables C language
project(template LANGUAGES C)

# Where the sources of the project are located
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Force CMake to output every compiler command executed
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_EXECUTABLE_SUFFIX .elf)
set(CMAKE_C_STANDARD 99)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(external/unity)
