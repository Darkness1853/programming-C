#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertSort(int* arr, int n, int* comparisons, int* swaps) {
    *comparisons = 0; 
    *swaps = 0;       

    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            (*comparisons)++; 
            if (arr[j - 1] > arr[j]) {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
                (*swaps)++; 
            } else {
                break; 
            }
        }
    }
}

void selectSort(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0; 
    *swaps = 0; 

    for (int i = 0; i < n - 1; i++) {
        int k = i;

        for (int j = i + 1; j < n; j++) {
            (*swaps)++; 
            if (arr[j] < arr[k]) {
                k = j;
            }
        }

        if (k != i) {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            (*comparisons)++; 
        }
    }
}

void bubbleSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, j, temp;
    *comparisons = 0;
    *swaps = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
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
    printf("+-------+---------------+---------------+---------------+---------------+\n");
    printf("|   N   | M+C теоретич. |      Убыв.    |    Случ.      |     Возр.     |\n");
    printf("+-------+---------------+---------------+---------------+---------------+\n");

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int arr[n], arr_copy[n], arr_reverse[n];

        generateReverseSortedArray(arr_reverse, n);
        int comparisons, swaps;
        insertSort(arr_reverse, n, &comparisons, &swaps);
        int theoretical_reverse = (n * n - n) + (2 * n - 2);
        printf("|  %d \t|\t%d\t|\t%d\t|\t", n, theoretical_reverse, swaps + comparisons);

        
        generateRandomArray(arr, n);
        insertSort(arr, n, &comparisons, &swaps);
        printf("%d\t|\t", swaps + comparisons);

        
        generateSortedArray(arr_copy, n);
        insertSort(arr_copy, n, &comparisons, &swaps);
        int theoretical_sorted = 3 * (n - 1); 
        printf("%d\t|\n",theoretical_sorted);
        printf("+-------+---------------+---------------+---------------+---------------+\n");
    }

    printf("Трудоемкость квадратичных методов сортировки\n");
    printf("+-----+---------+---------+-------------+--------+\n");
    printf("|  N  |                 M_факт+C_факт            |\n");
    printf("|     |---------+---------+-------------+--------+\n");
    printf("|     |  Select |  Bubble |    Shaker   | Insert |\n");
    printf("+-----+---------+---------+-------------+--------+\n");

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int arr[n], arr_copy[n], arr_reverse[n];
        generateRandomArray(arr, n);

        // Select
        int comparisons_select, swaps_select;
        selectSort(arr, n, &comparisons_select, &swaps_select);
        int select_total = swaps_select + comparisons_select;

        // Bubble
        generateRandomArray(arr, n);
        int comparisons_bubble, swaps_bubble;
        bubbleSort(arr, n, &comparisons_bubble, &swaps_bubble);
        int bubble_total = swaps_bubble + comparisons_bubble;

        // Shaker
        generateRandomArray(arr, n);
        int comparisons_shaker, swaps_shaker;
        shakerSort(arr, n, &comparisons_shaker, &swaps_shaker);
        int shaker_total = swaps_shaker + comparisons_shaker;

        // Insert
        generateRandomArray(arr, n);
        int comparisons_insert, swaps_insert;
        insertSort(arr, n, &comparisons_insert, &swaps_insert);
        int insert_total = swaps_insert + comparisons_insert;

        printf("| %d |%d\t|%d\t  |\t%d\t|%d\t |\n", n, select_total, bubble_total, shaker_total, insert_total);
        printf("+-----+---------+---------+-------------+--------+\n");
    }

    return 0;
}