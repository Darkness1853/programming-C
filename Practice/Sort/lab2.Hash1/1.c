#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

int add(Node** table, int size, int key, int* new) {
    int index = key % size;
    Node* head = table[index];
    *new = 1;

    Node* current = head;
    while (current != NULL) {
        if (current->key == key) {
            *new = 0;
            return 0;
        }
        current = current->next;
    }

    int collision = (head != NULL);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) exit(1);
    newNode->key = key;
    newNode->next = head;
    table[index] = newNode;

    return collision;
}

void clear(Node** table, int size) {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current) {
            Node* tmp = current;
            current = current->next;
            free(tmp);
        }
    }
    free(table);
}

void makeText(char* buffer, int size) {
    const char chars[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.  Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    for (int i = 0; i < size - 1; i++) {
        buffer[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    buffer[size - 1] = '\0';
}

int main() {
    setlocale(LC_ALL, "Russian"); 
    
    srand(time(0));

    int sizes[] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 47,77,89,};
    int count = sizeof(sizes) / sizeof(sizes[0]);

    int textLength = 1000;
    char* text = (char*)malloc(textLength + 1);
    makeText(text, textLength + 1);

    printf("\n Анализ хеш-таблицы методом цепочек \n");
    printf("+----------------+--------------------+--------------+\n");
    printf("| Размер таблицы | Уникальные символы | Коллизии     |\n");
    printf("+----------------+--------------------+--------------+\n");

    for (int i = 0; i < count; i++) {
        int currentSize = sizes[i];

        Node** table = (Node**)calloc(currentSize, sizeof(Node*));
        if (!table) {
            printf("Ошибка выделения памяти.\n");
            free(text);
            return 1;
        }

        int collisions = 0;
        int unique = 0;

        for (int j = 0; j < textLength && text[j] != '\0'; j++) {
            int isNew;
            collisions += add(table, currentSize, (int)text[j], &isNew);
            if (isNew) unique++;
        }

        printf("| %14d | %18d | %12d |\n", currentSize, unique, collisions);


        clear(table, currentSize);
    }

    printf("+----------------+--------------------+--------------+\n");

    free(text);
    return 0;
}