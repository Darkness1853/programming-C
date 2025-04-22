#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, j, temp;
    *comparisons = 0;
    *swaps = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                // обмен значениями
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
            }
        }
    }
}

int calculateChecksum(int arr[], int n) {
    int checksum = 0;
    for (int i = 0; i < n; i++) {
        checksum += arr[i];
    }
    return checksum;
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void generateSortedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i; // возрастающий массив
    }
}

void generateReverseSortedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i - 1; // убывающий массив
    }
}

int main() {
    srand(time(NULL)); // случайные числа

    int sizes[] = {100, 200, 300, 400, 500};
    printf("+-------+---------------+---------------+---------------+---------------+\n");
    printf("|   N   | M+C теоретич. |      Убыв.    |    Случ.      |     Возр.     |\n");
    printf("+-------+---------------+---------------+---------------+---------------+\n");

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int arr[n], arr_copy[n], arr_reverse[n];

        // Убывающий массив
        generateReverseSortedArray(arr_reverse, n);
        int comparisons, swaps;
        bubbleSort(arr_reverse, n, &comparisons, &swaps);
        int checksum_reverse = calculateChecksum(arr_reverse, n);
        printf("|  %d \t|\t%d\t|\t%d\t|\t", n, 4*(n * (n - 1)) / 2, 4*(n * (n - 1)) / 2);

        // Случайный массив
        generateRandomArray(arr, n);
        bubbleSort(arr, n, &comparisons, &swaps);
        int checksum_random = calculateChecksum(arr, n);
        printf("%d\t|\t", swaps+comparisons);

        // Возрастающий массив
        generateSortedArray(arr_copy, n);
        bubbleSort(arr_copy, n, &comparisons, &swaps);
        int checksum_sorted = calculateChecksum(arr_copy, n);
        printf("%d\t|\n", swaps+comparisons);
        printf("+-------+---------------+---------------+---------------+---------------+\n");
    }

    return 0;
}