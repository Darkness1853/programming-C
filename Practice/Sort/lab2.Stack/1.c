#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

typedef struct tData
{
    struct tData *next;
    int data;
} tData;


void AddToStack(tData** head, int data)
{
    tData* p = (tData*)malloc(sizeof(tData));
    p->data = data;
    p->next = *head;
    *head = p;
}


void fillIncStack(tData **head, int n)
{
    for (int i = 1; i <= n; i++)
    {
        AddToStack(head, i);
    }
}


void fillDecStack(tData** head, int n)
{
    for (int i = n; i >= 1; i--)
    {
        AddToStack(head, i);
    }
}

void fillRanStack(tData** head, int n)
{
    srand(time(NULL));
    for (int i = 1; i <= n; i++)
    {
        int ranNum = rand() % 100;
        AddToStack(head, ranNum);
    }
}


void AddToQueue(tData** head, tData** tail, int data)
{
    tData *p = (tData *)malloc(sizeof(tData));
    p->data = data;
    p->next = NULL;

    if (*tail == NULL)
    {
        *head = *tail = p;
    }
    else
    {
        (*tail)->next = p;
        *tail = p;
    }
}


void fillIncQueue(tData** head, tData** tail, int n)
{
    for (int i = 1; i <= n; i++)
    {
        AddToQueue(head, tail, i);
    }
}


void fillDecQueue(tData** head, tData** tail, int n)
{
    for (int i = n; i >= 1; i--)
    {
        AddToQueue(head, tail, i);
    }
}

void fillRanQueue(tData** head, tData** tail, int n)
{
    srand(time(NULL));
    for (int i = 1; i <= n; i++)
    {
        int ranNum = rand() % 100;
        AddToQueue(head, tail, ranNum);
    }
}

void delStackElement(tData** head)
{
    if (head != NULL)
    {
        tData *p = *head;
        *head = p->next;
        free(p);
    }
}

void print_list(tData *head)
{
    tData *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int checksum(tData *head)
{
    int sum = 0;
    tData *p = head;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int count_series(tData *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int count = 1;
    tData *p = head;

    while (p->next != NULL)
    {
        if (p->data > p->next->data)
        {
            count++;
        }
        p = p->next;
    }
    return count;
}

void clear(tData *head)
{
    tData *p = head;
    while (p != NULL)
    {
        tData *temp_p = p;
        p=p->next;
        free(temp_p);
    }
    printf("\n");
}

void printForwardRecursive(tData *head)
{
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    printForwardRecursive(head->next);
}

void printBackwardRecursive(tData *head)
{
    if (head == NULL) {
        return;
    }
    printBackwardRecursive(head->next);
    printf("%d ", head->data);
}


int main() {
    tData* stack_head = NULL;
    fillIncStack(&stack_head, N);
    printf("Стек (убывающий): ");
    print_list(stack_head);
    printf("Контрольная сумма: %d\n", checksum(stack_head));
    printf("Количество серий: %d\n", count_series(stack_head));
    clear(stack_head);

    stack_head = NULL;
    fillDecStack(&stack_head, N);
    printf("Стек (возрастающий): ");
    print_list(stack_head);
    printf("Контрольная сумма: %d\n", checksum(stack_head));
    printf("Количество серий: %d\n", count_series(stack_head));
    clear(stack_head);

    stack_head = NULL;
    fillRanStack(&stack_head, N);
    printf("Стек (Случайный): ");
    print_list(stack_head);
    printf("Контрольная сумма: %d\n", checksum(stack_head));
    printf("Количество серий: %d\n", count_series(stack_head));
    clear(stack_head);

    tData* queue_head = NULL, *queue_tail = NULL;
    fillIncQueue(&queue_head, &queue_tail, N);
    printf("Очередь(возрастающая): ");
    print_list(queue_head);
    printf("Контрольная сумма: %d\n", checksum(queue_head));
    printf("Количество серий: %d\n", count_series(queue_head));
    clear(queue_head);

    queue_head = NULL;
    queue_tail = NULL;
    fillDecQueue(&queue_head, &queue_tail, N);
    printf("Очередь (убывающая): ");
    print_list(queue_head);
    printf("Контрольная сумма: %d\n", checksum(queue_head));
    printf("Количество серий: %d\n", count_series(queue_head));
    clear(queue_head);

    queue_head = NULL; 
    queue_tail = NULL;
    fillRanQueue(&queue_head, &queue_tail, N);
    printf("Очередь(случайная): ");
    print_list(queue_head);
    printf("Контрольная сумма: %d\n", checksum(queue_head));
    printf("Количество серий: %d\n", count_series(queue_head));
    clear(queue_head);

    queue_head = NULL;
    queue_tail = NULL;
    fillRanQueue(&queue_head, &queue_tail, N);

    printf("Очередь в прямом порядке: ");
    printForwardRecursive(queue_head);

    printf("Очередь в обратном порядке: ");
    printBackwardRecursive(queue_head);
    printf("\n");

    clear(queue_head);

    return 0;
}