cmake_minimum_required(VERSION 3.10)
project(inverse_matrix C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Основная программа
add_executable(inverse_matrix
    src/matrix.c
    main.c
)

# Подключаем заголовочные файлы
target_include_directories(inverse_matrix PRIVATE include)

enable_testing()

add_subdirectory(test)