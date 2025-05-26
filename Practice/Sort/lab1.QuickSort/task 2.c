#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
    /*
    if (j - L < R - i) {
        QuickSort(arr, L, j, counts);
        L = i;
    } else {
        QuickSort(arr, i, R, counts);
        R = j;
    }
    */
    }
    if (L < j) QuickSort(arr, L, j, counts);
    if (i < R) QuickSort(arr, i, R, counts);
}

int calcTheoretic(int n) {
    double log2n = log2((double)n);
    double C = 2 * n * log2n;
    double M = (n * log2n) / 3;
    return (int)(M + C + 0.5);
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
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

int calculateChecksum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    srand(time(NULL));

    int sizes[] = {100, 200, 300, 400, 500};
    printf("Трудоемкость QuickSort (М_факт + С_факт)\n");
    printf("+-------+---------------+---------------+---------------+\n");
    printf("|   N   |   Убывающий   |   Случайный   |  Возрастающий |\n");
    printf("+-------+---------------+---------------+---------------+\n");

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int arr[n], arr_sorted[n], arr_reverse[n];
        int theoretical = calcTheoretic(n);

        generateReverseSortedArray(arr_reverse, n);
        OperationCount rev_counts = {0, 0};
        QuickSort(arr_reverse, 0, n - 1, &rev_counts);
        printf("| %d\t|    %d\t|", n, rev_counts.comparisons + rev_counts.swaps);

        generateRandomArray(arr, n);
        OperationCount rand_counts = {0, 0};
        QuickSort(arr, 0, n - 1, &rand_counts);
        printf("    %d\t|", rand_counts.comparisons + rand_counts.swaps);

        generateSortedArray(arr_sorted, n);
        OperationCount sorted_counts = {0, 0};
        QuickSort(arr_sorted, 0, n - 1, &sorted_counts);
        printf("    %d\t|\n", sorted_counts.comparisons + sorted_counts.swaps);
        printf("+-------+---------------+---------------+---------------+\n");
    }

    return 0;
}