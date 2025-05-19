cmake_minimum_required(VERSION 3.10)
project(inverse_matrix C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Main executable
add_executable(inverse_matrix
    src/matrix.c
    main.c
)

# Testing executable
enable_testing()
add_executable(test_matrix
    src/matrix.c
    tests/test_matrix.c
)
add_test(NAME matrix_test COMMAND test_matrix)

# Include directories
target_include_directories(inverse_matrix PRIVATE include)
target_include_directories(test_matrix PRIVATE include)
target_link_libraries(inverse_matrix m)
target_link_libraries(test_matrix m)