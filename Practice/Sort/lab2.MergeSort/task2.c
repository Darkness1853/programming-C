#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Node {
    long long int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int count;
} LinkedList;

Node* createNode(long long int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void initList(LinkedList* list) {
    list->head = list->tail = NULL;
    list->count = 0;
}

void appendNode(LinkedList* list, long long int val) {
    Node* newNode = createNode(val);
    if (list->tail == NULL) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->count++;
}

void populateAscending(LinkedList* list, int n) {
    for (int i = 1; i <= n; i++) {
        appendNode(list, i);
    }
}

void populateDescending(LinkedList* list, int n) {
    for (int i = n; i >= 1; i--) {
        appendNode(list, i);
    }
}

void populateRandom(LinkedList* list, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        appendNode(list, rand() % (2*n));
    }
}

void clearMemory(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = list->tail = NULL;
    list->count = 0;
}

void moveNode(LinkedList* destination, LinkedList* source, int* operations) {
    if (source->head == NULL) return;
    Node* node = source->head;
    source->head = source->head->next;
    if (source->head == NULL) source->tail = NULL;
    source->count--;
    node->next = NULL;
    if (destination->tail == NULL) {
        destination->head = destination->tail = node;
    } else {
        destination->tail->next = node;
        destination->tail = node;
    }
    destination->count++;
    (*operations)++;
}

void merge(LinkedList* left, int leftSize, LinkedList* right, int rightSize, 
           LinkedList* result, int* moves, int* comparisons) {
    while (leftSize > 0 && rightSize > 0) {
        (*comparisons)++;
        if (left->head->data <= right->head->data) {
            moveNode(result, left, moves);
            leftSize--;
        } else {
            moveNode(result, right, moves);
            rightSize--;
        }
    }
    
    while (leftSize > 0) {
        moveNode(result, left, moves);
        leftSize--;
    }
    
    while (rightSize > 0) {
        moveNode(result, right, moves);
        rightSize--;
    }
}

void splitList(LinkedList* original, LinkedList* leftHalf, LinkedList* rightHalf) {
    initList(leftHalf);
    initList(rightHalf);
    if (original->head == NULL) return;
    Node* slow = original->head;
    Node* fast = original->head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    leftHalf->head = original->head;
    leftHalf->tail = slow;
    rightHalf->head = slow->next;
    rightHalf->tail = original->tail;
    Node* current = leftHalf->head;
    leftHalf->count = 0;
    while (current != NULL && current != rightHalf->head) {
        leftHalf->count++;
        current = current->next;
    }
    rightHalf->count = original->count - leftHalf->count;
    if (leftHalf->tail) leftHalf->tail->next = NULL;
}

int MergeSort(LinkedList* list) {
    if (list->head == NULL || list->head->next == NULL) return 0;
    LinkedList left, right;
    splitList(list, &left, &right);
    int leftOperations = MergeSort(&left);
    int rightOperations = MergeSort(&right);
    int totalMoves = 0, totalComparisons = 0;
    LinkedList temp;
    initList(&temp);
    merge(&left, left.count, &right, right.count, &temp, &totalMoves, &totalComparisons);
    *list = temp;
    return totalMoves + totalComparisons + leftOperations + rightOperations;
}

int calculateExpectedComparisons(int n) {
    return (int)(n * (log2(n)));
}

int calculateExpectedMoves(int n) {
    return (int)(n * (log2(n)));
}

int calculateTotalExpected(int n) {
    return calculateExpectedComparisons(n) + calculateExpectedMoves(n);
}

int main() {
    int sizes[] = {100, 200, 300, 400, 500};
    int numSizes = sizeof(sizes)/sizeof(sizes[0]);
    
    printf("+-------+---------------+---------------+---------------+------------------------+\n");
    printf("|   N   | Теоретическая |             Трудоемкость (M + C)                       |\n");
    printf("+       |       M+C     +------------------+------------------+------------------+\n");
    printf("|       |               |   Убывающий      |  Случайный       | Возрастающий     |\n");
    printf("+-------+---------------+------------------+------------------+------------------+\n");
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int theoretical = calculateTotalExpected(n);
        int descending, random, ascending;
        
        LinkedList descList;
        initList(&descList);
        populateDescending(&descList, n);
        descending = MergeSort(&descList);
        clearMemory(&descList);
        
        LinkedList randList;
        initList(&randList);
        populateRandom(&randList, n);
        random = MergeSort(&randList);
        clearMemory(&randList);
        
        LinkedList ascList;
        initList(&ascList);
        populateAscending(&ascList, n);
        ascending = MergeSort(&ascList);
        clearMemory(&ascList);
        
        printf("|  %d  |  %10d   |  %15d |  %15d |  %15d |\n", 
               n, theoretical, descending, random, ascending);
    }
    printf("+-------+---------------+------------------+------------------+------------------+\n");
}