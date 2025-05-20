# Поиск библиотеки cmocka
find_library(CMOCKA_LIBRARY cmocka)
find_path(CMOCKA_INCLUDE_DIR cmocka.h)

if(CMOCKA_LIBRARY AND CMOCKA_INCLUDE_DIR)
    message(STATUS "Найден cmocka: ${CMOCKA_LIBRARY}")
    
    # Создаем тестовый исполняемый файл
    add_executable(test_matrix
        test_matrix.c
        ../src/matrix.c
    )
    
    # Подключаем заголовочные файлы
    target_include_directories(test_matrix PRIVATE ../include ${CMOCKA_INCLUDE_DIR})
    
    # Подключаем cmocka
    target_link_libraries(test_matrix ${CMOCKA_LIBRARY})
    
    # Добавляем тест
    add_test(NAME matrix_tests COMMAND test_matrix)
else()
    message(WARNING "cmocka не найден, тестирование нельзя сделать")
endif()