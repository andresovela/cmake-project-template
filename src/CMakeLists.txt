# Declares all the source files in the ${SOURCE_FILES} variable
include(${CMAKE_SOURCE_DIR}/cmake/source_files.cmake)

# Declares all the include paths in the ${INCLUDE_PATHS} variable
include(${CMAKE_SOURCE_DIR}/cmake/include_directories.cmake)

# Adds project target
add_executable(${PROJECT_NAME} main.c ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_PATHS})