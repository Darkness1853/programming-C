#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* first;
    QueueNode* end;
} Queue;

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

void push(StackNode** top, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(StackNode** top) {
    if (*top == NULL) return -1;
    StackNode* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

void fillStackDecreasing(StackNode** top, int n) {
    for (int i = 1; i <= n; i++) {
        push(top, i);
    }
}

void fillStackIncreasing(StackNode** top, int n) {
    for (int i = n; i >= 1; i--) {
        push(top, i);
    }
}

void fillStackRandom(StackNode** top, int n, int minVal, int maxVal) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = minVal + rand() % (maxVal - minVal + 1);
        push(top, num);
    }
}

void enqueue(Queue* q, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (q->end == NULL) {
        q->first = q->end = newNode;
    } else {
        q->end->next = newNode;
        q->end = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->first == NULL) return -1;
    QueueNode* temp = q->first;
    int data = temp->data;
    q->first = q->first->next;
    if (q->first == NULL) q->end = NULL;
    free(temp);
    return data;
}

void fillQueueIncreasing(Queue* q, int n) {
    for (int i = 1; i <= n; i++) {
        enqueue(q, i);
    }
}

void fillQueueDecreasing(Queue* q, int n) {
    for (int i = n; i >= 1; i--) {
        enqueue(q, i);
    }
}

void fillQueueRandom(Queue* q, int n, int minVal, int maxVal) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = minVal + rand() % (maxVal - minVal + 1);
        enqueue(q, num);
    }
}

void insertToList(ListNode** head, int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int calculateChecksum(ListNode* head) {
    int sum = 0;
    ListNode* current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

int countSeries(ListNode* head) {
    if (head == NULL) return 0;
    int count = 1;
    ListNode* current = head;
    while (current->next != NULL) {
        if (current->data != current->next->data) {
            count++;
        }
        current = current->next;
    }
    return count;
}

ListNode* stackToList(StackNode* top) {
    ListNode* list = NULL;
    StackNode* current = top;
    while (current != NULL) {
        insertToList(&list, current->data);
        current = current->next;
    }
    return list;
}

ListNode* queueToList(Queue* q) {
    ListNode* list = NULL;
    QueueNode* current = q->first;
    while (current != NULL) {
        insertToList(&list, current->data);
        current = current->next;
    }
    return list;
}

void freeStack(StackNode** top) {
    while (*top != NULL) {
        pop(top);
    }
}

void freeQueue(Queue* q) {
    while (q->first != NULL) {
        dequeue(q);
    }
}

void freeList(ListNode** head) {
    ListNode* current = *head;
    while (current != NULL) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void printStack(StackNode* top) {
    StackNode* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printQueue(Queue* q) {
    QueueNode* current = q->first;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int a = 10;
    int b = 10;
    
    printf("Работа со стеком:\n");
    
    StackNode* stack = NULL;
    fillStackIncreasing(&stack, a);
    printf("Стек (возрастающие числа): ");
    printStack(stack);
    
    ListNode* stackList = stackToList(stack);
    printf("Контрольная сумма: %d\n", calculateChecksum(stackList));
    printf("Количество серий: %d\n", countSeries(stackList));
    freeList(&stackList);
    
    freeStack(&stack);
    
    fillStackDecreasing(&stack, a);
    printf("Стек (убывающие числа): ");
    printStack(stack);
    
    stackList = stackToList(stack);
    printf("Контрольная сумма: %d\n", calculateChecksum(stackList));
    printf("Количество серий: %d\n", countSeries(stackList));
    freeList(&stackList);
    
    freeStack(&stack);
    
    fillStackRandom(&stack, a, 1, b);
    printf("Стек (случайные числа): ");
    printStack(stack);
    
    stackList = stackToList(stack);
    printf("Контрольная сумма: %d\n", calculateChecksum(stackList));
    printf("Количество серий: %d\n\n", countSeries(stackList));
    freeList(&stackList);
    
    freeStack(&stack);
    
    printf("Работа с очередью:\n");
    
    Queue queue = {NULL, NULL};
    fillQueueIncreasing(&queue, a);
    printf("Очередь (возрастающие числа): ");
    printQueue(&queue);
    
    ListNode* queueList = queueToList(&queue);
    printf("Контрольная сумма: %d\n", calculateChecksum(queueList));
    printf("Количество серий: %d\n", countSeries(queueList));
    freeList(&queueList);
    
    freeQueue(&queue);
    
    fillQueueDecreasing(&queue, a);
    printf("Очередь (убывающие числа): ");
    printQueue(&queue);
    
    queueList = queueToList(&queue);
    printf("Контрольная сумма: %d\n", calculateChecksum(queueList));
    printf("Количество серий: %d\n", countSeries(queueList));
    freeList(&queueList);
    
    freeQueue(&queue);
    
    fillQueueRandom(&queue, a, 1, b);
    printf("Очередь (случайные числа): ");
    printQueue(&queue);
    
    queueList = queueToList(&queue);
    printf("Контрольная сумма: %d\n", calculateChecksum(queueList));
    printf("Количество серий: %d\n\n", countSeries(queueList));
    freeList(&queueList);
    
    freeQueue(&queue);
    
    printf("Работа со списком:\n");
    
    ListNode* list = NULL;
    insertToList(&list, 1);
    insertToList(&list, 2);
    insertToList(&list, 2);
    insertToList(&list, 3);
    insertToList(&list, 3);
    insertToList(&list, 3);
    
    printf("Список: ");
    printList(list);
    
    printf("Контрольная сумма: %d\n", calculateChecksum(list));
    printf("Количество серий: %d\n", countSeries(list));
    
    freeList(&list);
    
    return 0;
}
