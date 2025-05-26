#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int comparisons; 
    int swaps;       
} OperationCount;

void swap(int *a, int *b, OperationCount *counts) {
    int temp = *a;
    *a = *b;
    *b = temp;
    counts->swaps++;
}

void QuickSort(int arr[], int L, int R, OperationCount *counts) {
    if (L >= R) return;

    int x = arr[L]; 
    int i = L;
    int j = R;

    while (i <= j) {
        while (arr[i] < x) {
            counts->comparisons++;
            i++;
        }
        counts->comparisons++; 

        while (arr[j] > x) {
            counts->comparisons++;
            j--;
        }
        counts->comparisons++; 

        if (i <= j) {
            swap(&arr[i], &arr[j], counts);
            i++;
            j--;
        }
    }

    
    if (L < j) QuickSort(arr, L, j, counts);
    if (i < R) QuickSort(arr, i, R, counts);
}

void checkSort(int arr[], int n, int *controlSum, int *series) {
    *controlSum = 0;
    *series = 1;

    for (int i = 0; i < n; i++) {
        *controlSum += arr[i];
        if (i > 0 && arr[i] < arr[i-1]) {
            (*series)++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }
}

void generateAscendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void generateDescendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i - 1;
    }
}

int main() {
    srand(time(NULL));

    int n = 100; 
    int arr[n];

    printf("Тест QuickSort (n = %d)\n", n);

    generateRandomArray(arr, n);
    OperationCount randomCounts = {0, 0};
    printf("\nСлучайный массив:\n");
    QuickSort(arr, 0, n-1, &randomCounts);
    int controlSum, series;
    checkSort(arr, n, &controlSum, &series);
    printf("Контрольная сумма: %d\n", controlSum);
    printf("Число серий: %d\n", series);
    printf("Сравнений (Сф): %d\n", randomCounts.comparisons);
    printf("Перестановок (Мф): %d\n", randomCounts.swaps);
    printf("Общая трудоемкость (Мф + Сф): %d\n", randomCounts.comparisons + randomCounts.swaps);

    generateAscendingArray(arr, n);
    OperationCount ascendingCounts = {0, 0};
    printf("\nВозрастающий массив:\n");
    QuickSort(arr, 0, n-1, &ascendingCounts);
    checkSort(arr, n, &controlSum, &series);
    printf("Контрольная сумма: %d\n", controlSum);
    printf("Число серий: %d\n", series);
    printf("Сравнений (Сф): %d\n", ascendingCounts.comparisons);
    printf("Перестановок (Мф): %d\n", ascendingCounts.swaps);
    printf("Общая трудоемкость (Мф + Сф): %d\n", ascendingCounts.comparisons + ascendingCounts.swaps);

    generateDescendingArray(arr, n);
    OperationCount descendingCounts = {0, 0};
    printf("\nУбывающий массив:\n");
    QuickSort(arr, 0, n-1, &descendingCounts);
    checkSort(arr, n, &controlSum, &series);
    printf("Контрольная сумма: %d\n", controlSum);
    printf("Число серий: %d\n", series);
    printf("Сравнений (Сф): %d\n", descendingCounts.comparisons);
    printf("Перестановок (Мф): %d\n", descendingCounts.swaps);
    printf("Общая трудоемкость (Мф + Сф): %d\n", descendingCounts.comparisons + descendingCounts.swaps);

    return 0;
}