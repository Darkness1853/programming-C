#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_INPUT 100

typedef struct Node {
    char key[MAX_KEY_LEN];
    struct Node* next;
} Node;

typedef struct HashTable {
    int size;
    Node** table;
    int collisions;
} HashTable;

// Простая хеш-функция
int hash(char* key, int size) {
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % size;
}

// Создание таблицы
HashTable* create_table(int size) {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->size = size;
    ht->collisions = 0;
    ht->table = malloc(sizeof(Node*) * size);
    for (int i = 0; i < size; i++)
        ht->table[i] = NULL;
    return ht;
}

// Вставка с подсчетом коллизий
void insert(HashTable* ht, char* key) {
    int index = hash(key, ht->size);
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->key, key);
    new_node->next = NULL;

    if (ht->table[index] != NULL)
        ht->collisions++;

    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

// Вывод таблицы
void print_table(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        printf("[%d]: ", i);
        Node* curr = ht->table[i];
        while (curr != NULL) {
            printf("%s -> ", curr->key);
            curr = curr->next;
        }
        printf("NULL\n");
    }
    printf("Фактическое количество коллизий: %d\n", ht->collisions);
}

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

void test_collisions(char keys[][MAX_KEY_LEN], int num_keys) {
    printf("Размер\tКол-во ключей\tКоллизии\n");
    for (int size = 11; size <= 101; size++) {
        if (!is_prime(size)) continue;

        HashTable* ht = create_table(size);
        for (int i = 0; i < num_keys; i++)
            insert(ht, keys[i]);

        printf("%d\t%d\t\t%d\n", size, num_keys, ht->collisions);
        free(ht->table);
        free(ht);
    }
}

void search(HashTable* ht, char* key) {
    int index = hash(key, ht->size);
    Node* curr = ht->table[index];
    int pos = 0;

    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            printf("Элемент '%s' найден в списке %d, позиция %d\n", key, index, pos);
            return;
        }
        curr = curr->next;
        pos++;
    }
    printf("Элемент '%s' не найден.\n", key);
}

int main() {
    char input[MAX_INPUT][MAX_KEY_LEN] = {
        "apple", "banana", "grape", "melon", "peach", "cherry",
        "plum", "kiwi", "orange", "lemon", "lime", "mango",
        "fig", "pear", "date", "apricot", "berry", "coconut",
        "papaya", "guava"
    };
    int n = 20;

    // Задание 1
    HashTable* ht = create_table(17);
    for (int i = 0; i < n; i++)
        insert(ht, input[i]);
    print_table(ht);

    // Задание 2
    test_collisions(input, n);

    // Задание 3
    search(ht, "melon");
    search(ht, "dragonfruit");

    // Очистка памяти
    for (int i = 0; i < ht->size; i++) {
        Node* curr = ht->table[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);

    return 0;
}