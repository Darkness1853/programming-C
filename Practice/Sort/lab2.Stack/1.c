#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct StackElement {
    int value;
    struct StackElement* next;
} StackElement;

typedef struct QueueElement {
    int value;
    struct QueueElement* next;
} QueueElement;

typedef struct {
    QueueElement* front;
    QueueElement* rear;
} Queue;

typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

void addToStack(StackElement** head, int value) {
    StackElement* newElement = (StackElement*)malloc(sizeof(StackElement));
    newElement->value = value;
    newElement->next = *head;
    *head = newElement;
}

int removeFromStack(StackElement** head) {
    if (*head == NULL) return -1;
    StackElement* temp = *head;
    int value = temp->value;
    *head = (*head)->next;
    free(temp);
    return value;
}

void createAscendingStack(StackElement** head, int size) {
    for (int i = size; i >= 1; i--) {
        addToStack(head, i);
    }
}

void createDescendingStack(StackElement** head, int size) {
    for (int i = 1; i <= size; i++) {
        addToStack(head, i);
    }
}

void createRandomStack(StackElement** head, int size, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int num = min + rand() % (max - min + 1);
        addToStack(head, num);
    }
}

void addToQueue(Queue* q, int value) {
    QueueElement* newElement = (QueueElement*)malloc(sizeof(QueueElement));
    newElement->value = value;
    newElement->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newElement;
    } else {
        q->rear->next = newElement;
        q->rear = newElement;
    }
}

int removeFromQueue(Queue* q) {
    if (q->front == NULL) return -1;
    QueueElement* temp = q->front;
    int value = temp->value;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return value;
}

void createAscendingQueue(Queue* q, int size) {
    for (int i = 1; i <= size; i++) {
        addToQueue(q, i);
    }
}

void createDescendingQueue(Queue* q, int size) {
    for (int i = size; i >= 1; i--) {
        addToQueue(q, i);
    }
}

void createRandomQueue(Queue* q, int size, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int num = min + rand() % (max - min + 1);
        addToQueue(q, num);
    }
}

void addToList(ListElement** head, int value) {
    ListElement* newElement = (ListElement*)malloc(sizeof(ListElement));
    newElement->value = value;
    newElement->next = *head;
    *head = newElement;
}

void displayList(ListElement* head) {
    ListElement* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int computeSum(ListElement* head) {
    int sum = 0;
    ListElement* current = head;
    while (current != NULL) {
        sum += current->value;
        current = current->next;
    }
    return sum;
}

int countSequences(ListElement* head) {
    if (head == NULL) return 0;
    int count = 1;
    ListElement* current = head;
    
    while (current->next != NULL) {
        if (current->value > current->next->value) {
            count++;
        }
        current = current->next;
    }
    return count;
}

ListElement* convertStackToList(StackElement* head) {
    ListElement* list = NULL;
    StackElement* current = head;
    while (current != NULL) {
        addToList(&list, current->value);
        current = current->next;
    }
    return list;
}

ListElement* convertQueueToList(Queue* q) {
    ListElement* list = NULL;
    QueueElement* current = q->front;
    while (current != NULL) {
        addToList(&list, current->value);
        current = current->next;
    }
    return list;
}

void clearStack(StackElement** head) {
    while (*head != NULL) {
        removeFromStack(head);
    }
}

void clearQueue(Queue* q) {
    while (q->front != NULL) {
        removeFromQueue(q);
    }
}

void clearList(ListElement** head) {
    ListElement* current = *head;
    while (current != NULL) {
        ListElement* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void displayStack(StackElement* head) {
    StackElement* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void displayQueue(Queue* q) {
    QueueElement* current = q->front;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int stackSize = 10; 
    int maxRandom = 10; 

    printf("Стеки\n");
    
    StackElement* stack = NULL;
    createAscendingStack(&stack, stackSize);
    printf("Стек (возрастающие числа): ");
    displayStack(stack);
    
    ListElement* stackList = convertStackToList(stack);
    printf("Контрольная сумма: %d\n", computeSum(stackList));
    printf("Количество серий: %d\n", countSequences(stackList));
    clearList(&stackList);
    clearStack(&stack);

    createDescendingStack(&stack, stackSize);
    printf("\nСтек (убывающие числа): ");
    displayStack(stack);
    
    stackList = convertStackToList(stack);
    printf("Контрольная сумма: %d\n", computeSum(stackList));
    printf("Количество серий: %d\n", countSequences(stackList)); 
    clearList(&stackList);
    clearStack(&stack);

    createRandomStack(&stack, stackSize, 1, maxRandom);
    printf("\nСтек (случайные числа): ");
    displayStack(stack);
    
    stackList = convertStackToList(stack);
    printf("Контрольная сумма: %d\n", computeSum(stackList));
    printf("Количество серий: %d\n", countSequences(stackList));
    clearList(&stackList);
    clearStack(&stack);

    printf("\nОчереди\n");
    
    Queue queue = {NULL, NULL};
    
    createAscendingQueue(&queue, stackSize);
    printf("Очередь (возрастающие числа): ");
    displayQueue(&queue);
    
    ListElement* queueList = convertQueueToList(&queue);
    printf("Контрольная сумма: %d\n", computeSum(queueList));
    printf("Количество серий: %d\n", countSequences(queueList));
    clearList(&queueList);
    clearQueue(&queue);

    createDescendingQueue(&queue, stackSize);
    printf("\nОчередь (убывающие числа): ");
    displayQueue(&queue);
    
    queueList = convertQueueToList(&queue);
    printf("Контрольная сумма: %d\n", computeSum(queueList));
    printf("Количество серий: %d\n", countSequences(queueList));
    clearList(&queueList);
    clearQueue(&queue);

    createRandomQueue(&queue, stackSize, 1, maxRandom);
    printf("\nОчередь (случайные числа): ");
    displayQueue(&queue);
    
    queueList = convertQueueToList(&queue);
    printf("Контрольная сумма: %d\n", computeSum(queueList));
    printf("Количество серий: %d\n", countSequences(queueList));
    clearList(&queueList);
    clearQueue(&queue);
    printf("\nСписки\n");
    
    ListElement* list = NULL;
    addToList(&list, 4);
    addToList(&list, 4);
    addToList(&list, 2);
    addToList(&list, 8);
    addToList(&list, 5);
    addToList(&list, 9);
    addToList(&list, 1);
    
    printf("Список: ");
    displayList(list); 
    
    printf("Контрольная сумма: %d\n", computeSum(list));
    printf("Количество серий: %d\n", countSequences(list)); 
    
    clearList(&list);
    
    return 0;
}