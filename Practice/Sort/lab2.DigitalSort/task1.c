#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    int digits[10]; 
} Node;

Node* createNode(int value, int maxDigits) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    int num = value;
    for (int i = 0; i < maxDigits; i++) {
        newNode->digits[i] = num % 10;
        num /= 10;
    }
    
    return newNode;
}

void digitalSort(Node** head, int maxDigits, int* M) {
    Node* queues[10] = {NULL};
    Node* tails[10] = {NULL};
    
    for (int digitPos = 0; digitPos < maxDigits; digitPos++) {
        Node* current = *head;
        while (current != NULL) {
            int d = current->digits[digitPos];
            
            if (queues[d] == NULL) {
                queues[d] = current;
                tails[d] = current;
            } else {
                tails[d]->next = current;
                tails[d] = current;
            }
            (*M)++; 
            current = current->next;
        }
        
        *head = NULL;
        Node* last = NULL;
        for (int i = 0; i < 10; i++) {
            if (queues[i] != NULL) {
                if (*head == NULL) {
                    *head = queues[i];
                } else {
                    last->next = queues[i];
                }
                last = tails[i];
                queues[i] = NULL;
            }
        }
        if (last != NULL) {
            last->next = NULL;
        }
    }
}

int getMaxDigits(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    
    int digits = 0;
    while (max != 0) {
        digits++;
        max /= 10;
    }
    return digits;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int checksum(Node* head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int countRuns(Node* head) {
    if (head == NULL) return 0;
    int runs = 1;
    int prev = head->data;
    head = head->next;
    while (head != NULL) {
        if (head->data != prev) runs++;
        prev = head->data;
        head = head->next;
    }
    return runs;
}

int main() {
    int arr[] = {345, 241, 432, 124, 110, 453, 503, 352, 311, 215, 541, 102};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int maxDigits = getMaxDigits(arr, n);
    Node* head = NULL;
    Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        Node* newNode = createNode(arr[i], maxDigits);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    printf("Исходный список: ");
    printList(head);
    
    int M = 0;
    digitalSort(&head, maxDigits, &M);
    
    printf("Отсортированный список: ");
    printList(head);
    
    printf("Контрольная сумма: %d\n", checksum(head));
    printf("Число серий: %d\n", countRuns(head));
    printf("Фактическое количество перемещений (Mф): %d\n", M);
    printf("Теоретическая оценка (M): %d\n", n * maxDigits);
    
    // Освобождение памяти
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}