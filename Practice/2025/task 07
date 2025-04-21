#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t clock(void);
void selectionSort(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            (*swaps)++;
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main() {
    int arr1[] = {1,2,3,4,5,6,7,8,9,10}; 
    int arr2[] = {10,9,8,7,6,5,4,3,2,1}; 
    int arr3[] = {3, 1, 4, 1, 5, 9, 2, 6}; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    int comparisons1, swaps1, comparisons2, swaps2, comparisons3, swaps3;

    selectionSort(arr1, n1, &comparisons1, &swaps1);
    selectionSort(arr2, n2, &comparisons2, &swaps2);
    selectionSort(arr3, n3, &comparisons3, &swaps3);


    printf("Обратно отсортированный: Сравнений = %d, Обменов = %d\n", comparisons1, swaps1);
    printf("Отсортированный: Сравнений = %d, Обменов = %d\n", comparisons2, swaps2);
    printf("Случайный: Сравнений = %d, Обменов = %d\n", comparisons3, swaps3);

    return 0;
}