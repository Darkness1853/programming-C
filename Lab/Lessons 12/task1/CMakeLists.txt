# Задание: задать имя проекта и версию cmake, добавить subdirectory для background и pipes, в которых 
# тоже есть свои CMakeLists.txt (внутри них тоже нужно добавить одну-две строки для сборки, задание описано в них же)
# Решить проблему с заголовочными файлами, включив директории в корневом CMakeLists.txt (include_directories)
# Слинковать исполняемый файл из src/main.c с библиотекой background
# Все это дело собрать, используя cmake и make
# Для установки cmake нужно установить его: sudo apt install build-essential cmake -y
cmake_minimum_required(VERSION 3.10)

project(lab12)

add_subdirectory(background)
add_subdirectory(pipes)

add_executable(task1 src/main.c)

include_directories(background)

target_link_libraries(task1 background)
#создаем возможность запуска программы
add_custom_target(run
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/task1
    DEPENDS task1
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)