#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *key;
    struct Node *next;
} Node;

typedef struct {
    Node **table;
    int size;
    int collisions;
} HashTable;

int hash_function(const char *key, int m) {
    int h = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        h = (h * 256 + key[i]) % m;
    }
    return h;
}

HashTable* init_hash_table(int size) {
    HashTable *ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->collisions = 0;
    ht->table = (Node**)calloc(size, sizeof(Node*));
    return ht;
}

void hash_insert(HashTable *ht, const char *key) {
    int index = hash_function(key, ht->size);
    
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->next = NULL;
    
    if (ht->table[index] == NULL) {
        ht->table[index] = new_node;
    } else {
        new_node->next = ht->table[index];
        ht->table[index] = new_node;
        ht->collisions++;
    }
}

Node* hash_search(HashTable *ht, const char *key) {
    int index = hash_function(key, ht->size);
    Node *current = ht->table[index];
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

void print_hash_table(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        printf("[%d]: ", i);
        Node *current = ht->table[i];
        while (current != NULL) {
            printf("%s -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void free_hash_table(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        Node *current = ht->table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

int main() {
    printf("Демонстрация работы хеш-таблицы:\n");
    HashTable *ht = init_hash_table(17);
    
    // Вставляем элементы
    hash_insert(ht, "apple");
    hash_insert(ht, "banana");
    hash_insert(ht, "orange");
    hash_insert(ht, "grape");
    hash_insert(ht, "lemon");
    hash_insert(ht, "pear");
    hash_insert(ht, "kiwi");
    hash_insert(ht, "mango");
    hash_insert(ht, "peach");
    hash_insert(ht, "plum");
    hash_insert(ht, "apple"); // Дубликат
    
    // Выводим таблицу
    print_hash_table(ht);
    printf("Количество коллизий: %d\n\n", ht->collisions);
    
    // Поиск элементов
    printf("Поиск элементов:\n");
    char *search_keys[] = {"apple", "banana", "watermelon", "kiwi"};
    for (int i = 0; i < 4; i++) {
        Node *result = hash_search(ht, search_keys[i]);
        if (result) {
            printf("Найден: %s\n", result->key);
        } else {
            printf("Не найден: %s\n", search_keys[i]);
        }
    }
    
    free_hash_table(ht);
    return 0;
}