include(CTest)

set(TEST_NAME example2)
set(TEST_EXECUTABLE_NAME test_${TEST_NAME})

set(TEST_FILES
    ${CMAKE_SOURCE_DIR}/tests/example2/test_example2.c
    ${CMAKE_SOURCE_DIR}/tests/example2/test_example2_runner.c
)

# Declares all the source files in the ${SOURCE_FILES} variable
include(${CMAKE_SOURCE_DIR}/cmake/source_files.cmake)

# Declares all the include paths in the ${INCLUDE_PATHS} variable
include(${CMAKE_SOURCE_DIR}/cmake/include_directories.cmake)

add_executable(${TEST_EXECUTABLE_NAME} ${TEST_FILES} ${SOURCE_FILES})

target_include_directories(${TEST_EXECUTABLE_NAME} PUBLIC ${INCLUDE_PATHS})
target_link_libraries(${TEST_EXECUTABLE_NAME} unity)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_EXECUTABLE_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
