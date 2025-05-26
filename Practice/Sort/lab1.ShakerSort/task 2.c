#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;       

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
            }
        }
    }
}

void shakerSort(int* mass, int n, int *comparisons, int *swaps) {
    int left = 0, right = n - 1;
    int flag = 1;
    *comparisons = 0;
    *swaps = 0;

    while ((left < right) && flag > 0) {
        flag = 0;
        for (int i = left; i < right; i++) {
            (*comparisons)++;
            if (mass[i] > mass[i + 1]) {
                (*swaps)++;
                int t = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = t;
                flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            (*comparisons)++;
            if (mass[i - 1] > mass[i]) {
                (*swaps)++;
                int t = mass[i];
                mass[i] = mass[i - 1];
                mass[i - 1] = t;
                flag = 1;
            }
        }
        left++;
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
        arr[i] = i; 
    }
}

void generateReverseSortedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i - 1; 
    }
}

int main() {
    srand(time(NULL)); 

    int sizes[] = {100, 200, 300, 400, 500};
    printf("+-------+---------------+---------------+---------------+---------------+---------------+---------------+\n");
    printf("|   N   |               M_ф+C_ф пузырьковой             |               M_ф+C_ф шейкерной               |\n");
    printf("+       +---------------+---------------+---------------+---------------+---------------+---------------+\n");
    printf("|       |      Убыв.    |    Случ.      |     Возр.     |      Убыв.    |    Случ.      |     Возр.     |\n");
    printf("+-------+---------------+---------------+---------------+---------------+---------------+---------------+\n");

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int arr[n], arr_copy[n], arr_reverse[n];

        // Убывающий массив Bubblesort
        generateReverseSortedArray(arr_reverse, n);
        int comparisons, swaps;
        clock_t start = clock();
        bubbleSort(arr_reverse, n, &comparisons, &swaps);
        clock_t end = clock();
        printf("|  %d  |\t%d\t|\t", n, 4*(n * (n - 1)) / 2);

        // Случайный массив Bubblesort
        generateRandomArray(arr, n);
        bubbleSort(arr, n, &comparisons, &swaps);
        printf("%d\t|\t", swaps + comparisons);

        // Возрастающий массив Bubblesort
        generateSortedArray(arr_copy, n);
        bubbleSort(arr_copy, n, &comparisons, &swaps);
        printf("%d\t|", swaps + comparisons);

        // Убывающий массив Shakersort
        generateReverseSortedArray(arr_reverse, n);
        shakerSort(arr_reverse, n, &comparisons, &swaps);
        printf("\t%d\t|", 4*(n * (n - 1)) / 2);
        // Случайный массив Shakersort
        generateRandomArray(arr, n);
        shakerSort(arr, n, &comparisons, &swaps);
        printf("\t%d\t|", swaps + comparisons);

        // Возрастающий массив Shakersort
        generateSortedArray(arr_copy, n);
        shakerSort(arr_copy, n, &comparisons, &swaps);
        printf("\t%d\t|\n", n-1);
        printf("+-------+---------------+---------------+---------------+---------------+---------------+---------------+\n");
    }

    return 0;
}