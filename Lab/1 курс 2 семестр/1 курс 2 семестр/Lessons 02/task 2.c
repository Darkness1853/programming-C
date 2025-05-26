#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


void append(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head_ref;

    new_node->data = new_data; 
    new_node->next = NULL; 

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Иначе проходим до последнего узла
    while (last->next != NULL) {
        last = last->next;
    }

    // Меняем указатель последнего узла на новый узел
    last->next = new_node;
}

// Функция вывода списка на экран
void printList(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL; 
    int input;

    printf("Введите элементы списка (введите 0 для завершения программы и вывода результата.):\n");
    while (1) {
        printf("> ");
        scanf("%d", &input);
        if (input == 0) {
            break; 
        }
        append(&head, input); 
    }

    printf("Список: ");
    printList(head); 


    // Освобождение памяти
    struct node *current = head;
    struct node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}