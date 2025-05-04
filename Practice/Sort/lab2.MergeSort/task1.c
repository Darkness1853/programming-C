#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <stddef.h>

typedef struct Node {
    wchar_t data;
    struct Node* next;
} Node;

void printList(Node* head);
int listLength(Node* head);
int listChecksum(Node* head);
void splitList(Node* head, Node** a, Node** b, int* countA, int* countB);
void mergeLists(Node** result, Node* a, Node* b, int* comparisons, int* moves);
void mergeSort(Node** headRef, int n, int* totalComparisons, int* totalMoves);
void freeList(Node* head);

void printList(Node* head) {
    while (head != NULL) {
        wprintf(L"%lc ", head->data);
        head = head->next;
    }
    wprintf(L"\n");
}

int listLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int listChecksum(Node* head) {
    int sum = 0;
    while (head != NULL) {
        sum += (int)head->data;
        head = head->next;
    }
    return sum;
}

void splitList(Node* head, Node** a, Node** b, int* countA, int* countB) {
    *countA = *countB = 0;
    int toggle = 0;
    
    Node *tailA = NULL, *tailB = NULL;
    *a = *b = NULL;
    
    while (head != NULL) {
        if (toggle == 0) {
            if (*a == NULL) {
                *a = tailA = head;
            } else {
                tailA->next = head;
                tailA = head;
            }
            (*countA)++;
        } else {
            if (*b == NULL) {
                *b = tailB = head;
            } else {
                tailB->next = head;
                tailB = head;
            }
            (*countB)++;
        }
        head = head->next;
        toggle = 1 - toggle;
    }
    
    if (tailA) tailA->next = NULL;
    if (tailB) tailB->next = NULL;
}

void mergeLists(Node** result, Node* a, Node* b, int* comparisons, int* moves) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
    
    while (a != NULL && b != NULL) {
        (*comparisons)++;
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
        (*moves)++;
    }
    
    tail->next = (a != NULL) ? a : b;
    *result = dummy.next;
}

void mergeSort(Node** headRef, int n, int* totalComparisons, int* totalMoves) {
    if (n < 2) return;
    
    Node* head = *headRef;
    Node* a;
    Node* b;
    int countA, countB;
    
    splitList(head, &a, &b, &countA, &countB);
    
    mergeSort(&a, countA, totalComparisons, totalMoves);
    mergeSort(&b, countB, totalComparisons, totalMoves);
    
    mergeLists(headRef, a, b, totalComparisons, totalMoves);
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    setlocale(LC_ALL, "");
    
    wchar_t fio[] = L"НГУЕНЗУЙАНЬК";
    int n = wcslen(fio);
    
    // Создание списка
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = fio[i];
        newNode->next = NULL;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    wprintf(L"1. Исходные список: ");
    printList(head);
    
    Node* a = NULL;
    Node* b = NULL;
    int countA = 0, countB = 0;
    splitList(head, &a, &b, &countA, &countB);
    
    wprintf(L"2. Результат разделения списка:\n");
    wprintf(L"  Список A (%d): ", countA);
    printList(a);
    wprintf(L"  Список B (%d): ", countB);
    printList(b);
    
    Node* merged = NULL;
    int comparisons = 0, moves = 0;
    mergeLists(&merged, a, b, &comparisons, &moves);
    
    wprintf(L"3. Результат слияния списка:\n");
    wprintf(L"  Объединённый: ");
    printList(merged);
    wprintf(L"  Сравнений: %d\n", comparisons);
    wprintf(L"  Перемещений: %d\n", moves);
    wprintf(L"  Контр. сумма: %d\n", listChecksum(merged));
    
    Node* toSort = NULL;
    Node* sortTail = NULL;
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = fio[i];
        newNode->next = NULL;
        
        if (!toSort) {
            toSort = sortTail = newNode;
        } else {
            sortTail->next = newNode;
            sortTail = newNode;
        }
    }
    
    comparisons = 0;
    moves = 0;
    mergeSort(&toSort, n, &comparisons, &moves);
    
    wprintf(L"4. Результат сортировки:\n");
    wprintf(L"  Отсортированный: ");
    printList(toSort);
    wprintf(L"  Всего сравнений: %d\n", comparisons);
    wprintf(L"  Всего перемещений: %d\n", moves);
    
    freeList(merged);
    freeList(toSort);
    
    return 0;
}