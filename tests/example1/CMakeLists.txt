enable_testing()
include(CTest)

set(TEST_FILES
    ${CMAKE_SOURCE_DIR}/tests/example1/test_example1.c
    ${CMAKE_SOURCE_DIR}/tests/example1/test_example1_runner.c
)

# Declares all the source files in the ${SOURCE_FILES} variable
include(${CMAKE_SOURCE_DIR}/cmake/source_files.cmake)

# Declares all the include paths in the ${INCLUDE_PATHS} variable
include(${CMAKE_SOURCE_DIR}/cmake/include_directories.cmake)

add_executable(example1_app ${TEST_FILES} ${SOURCE_FILES})

target_include_directories(example1_app PUBLIC ${INCLUDE_PATHS})
target_link_libraries(example1_app unity)

add_test(suite_example1 example1_app)
