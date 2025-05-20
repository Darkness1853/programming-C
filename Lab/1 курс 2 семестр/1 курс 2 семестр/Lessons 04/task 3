#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//Цель задания: Заменить начальные буквы всех слов на прописные буквы и записать результирующий текст в новый файл.
//Инструкция:
//Программа требует минимум 2 аргумента
//Необходимо создать пустой текстовый файл в одной папке со скриптом
//gcc <название программы>.c -o <название>
//Ввести аргументы в таком формате: ./<программа> <текстовый файл в который запишеться> <сам текст на английском!>
void big_words(char *str) {
    int bigwords = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            bigwords = 1;
        } else {
            if (bigwords && islower(str[i])) {
                str[i] = toupper(str[i]);
            }
            bigwords = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Используйте: %s имя_файла текст текст ...\n", argv[0]);
        return 1;
    }

    // 1. Создаём файл и записываем слова через пробелы
    FILE *file = fopen(argv[1], "w");
    if (!file) {
        printf("Ошибка создания файла\n");
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        // Записываем текущий аргумент
        fprintf(file, "%s", argv[i]);
        if (i < argc - 1) {
            fprintf(file, " ");  
        } else {
            fprintf(file, "\n");
        }
    }
    fclose(file);

    // 2. Читаем файл, обрабатываем и сохраняем
    file = fopen(argv[1], "r");
    if (!file) {
        printf("Ошибка чтения файла\n");
        return 1;
    }

    char content[500];
    fgets(content, sizeof(content), file);
    fclose(file);
    big_words(content); 
    file = fopen(argv[1], "w"); // Перезаписываем исходный файл
    if (!file) {
        printf("Ошибка записи результата\n");
        return 1;
    }
    fprintf(file, "%s", content);
    fclose(file);

    printf("Результат: %s\n", content);
    return 0;
}