Лазарев. M _, [20.05.2025 12:16]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Проверка, является ли число простым
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Хеш-функция для символа
int hash(char c, int size) {
    return (c % size + size) % size; // Гарантирует положительный результат
}

// Подсчет уникальных символов в строке
int countUniqueChars(const char* str) {
    bool seen[256] = {false}; // Массив для отслеживания встреченных символов
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str[i];
        if (!seen[c]) {
            seen[c] = true;
            count++;
        }
    }
    return count;
}

// Вставка символа в хеш-таблицу с подсчетом коллизий
int insert(int *table, int size, char c, int method, int *collisions) {
    int key = hash(c, size);
    int initial_pos = key;
    int i = 0;
    int probeIndex;

    while (1) {
        if (method == 1) {
            probeIndex = (initial_pos + i) % size; // Линейное пробирование
        } else {
            probeIndex = (initial_pos + i * i) % size; // Квадратичное пробирование
        }

        if (table[probeIndex] == 0) {
            // Нашли пустую ячейку
            table[probeIndex] = (int)c;
            return 1; // Успешная вставка
        }

        if (table[probeIndex] == (int)c) {
            return 0; // Дубликат, не увеличиваем счетчик коллизий
        }

        // Регистрируем коллизию (если это не первая попытка)
        if (i > 0) {
            (*collisions)++;
        }

        i++;
        if (i >= size) {
            return -1; // Таблица переполнена
        }
    }
}

// Вывод хеш-таблицы
void printHashTable(int *table, int size, const char *method) {
    printf("%s хеш-таблица (размер %d):\n", method, size);
    for (int i = 0; i < size; i++) {
        if (table[i] == 0) {
            printf("- "); // Пустая ячейка
        } else {
            printf("%c ", table[i]); // Заполненная ячейка
        }
    }
    printf("\n\n");
}

int main() {
    // Исходный текст для анализа
    char key[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.  Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

Лазарев. M _, [20.05.2025 12:16]
// Подсчет уникальных символов
    int numKeys = countUniqueChars(key);
    printf("Общее количество уникальных символов: %d\n\n", numKeys);

    // Заголовок таблицы результатов
    printf("| %-15s | %-19s | %-19s | %-19s |\n", 
           "Размер таблицы", "Уникальные символы", 
           "Коллизии (Линейные)", 
           "Коллизии (Квадратичные)");
    printf("|-----------------|---------------------|-------------------------|-------------------------|\n");

    // Анализ для разных размеров таблицы
    for (int size = 11; size <= 101; size++) {
        if (!isPrime(size)) continue; // Используем только простые размеры
        
        int *linearTable = (int *)calloc(size, sizeof(int));
        int *quadraticTable = (int *)calloc(size, sizeof(int));
        
        if (linearTable == NULL || quadraticTable == NULL) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            return 1;
        }
        
        int linearCollisions = 0;
        int quadraticCollisions = 0;
        
        // Вставляем только уникальные символы
        bool seen[256] = {false};
        for (int j = 0; j < strlen(key); j++) {
            char c = key[j];
            if (seen[(unsigned char)c]) continue;
            seen[(unsigned char)c] = true;
            
            insert(linearTable, size, c, 1, &linearCollisions);
            insert(quadraticTable, size, c, 2, &quadraticCollisions);
        }
        
        // Вывод результатов для текущего размера
        printf("| %-15d | %-19d | %-23d | %-23d |\n", 
               size, numKeys, linearCollisions, quadraticCollisions);

        // Вывод таблиц для некоторых размеров (например, 37)
        if (size == 37) {
            printHashTable(linearTable, size, "Линейная");
            printHashTable(quadraticTable, size, "Квадратичная");
        }
        
        free(linearTable);
        free(quadraticTable);
    }
    
    return 0;
}