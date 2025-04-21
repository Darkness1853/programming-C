#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void HeapBuild(int arr[], int indexnow, int indexlast, int *C, int *M) {
    int maxindex;
    int done = 0;
    
    while ((indexnow * 2 <= indexlast) && (!done)) {
        if (indexnow * 2 == indexlast) {
            maxindex = indexnow * 2;
        } else if (arr[indexnow * 2] > arr[indexnow * 2 + 1]) {
            maxindex = indexnow * 2;
        } else {
            maxindex = indexnow * 2 + 1;
        }
        
        (*C)++;
        if (arr[indexnow] < arr[maxindex]) {
            (*M)++;
            int temp = arr[indexnow];
            arr[indexnow] = arr[maxindex];
            arr[maxindex] = temp;
            indexnow = maxindex;
        } else {
            done = 1;
        }
    }
}



void HeapSort(int arr[], int n, int *C, int *M) {
    *C = 0;
    *M = 0;
    
    // Построение пирамиды 
    for (int i = (n / 2) - 1; i >= 0; i--) {
        HeapBuild(arr, i, n - 1, C, M);
    }
    
    // Сортировка
    for (int i = n - 1; i >= 1; i--) {
        (*M)++;
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        HeapBuild(arr, 0, i - 1, C, M);
    }
}

// теор. трудоемкость M + C
int calcTheoretic(int n) {
    double log2n = log2((double)n);  
    double M = n * log2n + 6.5 * n - 4;
    double C = 2 * n * log2n + n + 2;
    return (int)(M + C + 0.5); 
}

int calculateChecksum(int arr[], int n) {
    int checksum = 0;
    for (int i = 0; i < n; i++) {
        checksum += arr[i];
    }
    return checksum;
}
int C = 0;
int M = 0;

void piram(int arr[], int L, int R) {
    int x = arr[L];
    int i = L;

    while (1) {
        int j = 2 * i;
        if (j > R) break;

        if (j < R) {
            if (arr[j + 1] > arr[j]) {
                C++;
                j = j + 1;
            }
        }

        if (x >= arr[j]) {
            C++;
            break;
        }

        M++;
        arr[i] = arr[j];
        i = j;
    }

    if (i != L) M++;
    M++;
    arr[i] = x;
}

void generateArray(int arr[], int n, int type) {
    switch (type) {
        case 0:
            for (int i = 0; i < n; i++) arr[i] = n - i;
            break;
        case 1:
            for (int i = 0; i < n; i++) arr[i] = rand() % (2 * n);
            break;
        case 2:
            for (int i = 0; i < n; i++) arr[i] = i + 1;
            break;
    }
}


void testHeap(int n) {
    int arr[n];
    int theoretical = 2 * log2(n) + log2(n) + 3;
    printf("|%4d", n);
    for (int type = 0; type < 3; type++) {
        generateArray(arr, n, type);
        C = M = 0;
        piram(arr, 1, n);
        printf("   | %10d ", C + M);
        
    }
    
    printf("|  %10d|\n", theoretical);
    printf("+-------+---------------+---------------+------------+------------+\n");
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

int main() {
    srand(time(NULL));

    int sizes[] = {100, 200, 300, 400, 500};
    
    printf("Трудоемкость построения пирамиды\n");
    printf("+-------+---------------+---------------+------------+------------+\n");
    printf("|   N   | Теоретическая |                 М_факт+С_факт           |\n");
    printf("+       |      M+C      +---------------+------------+------------+\n");
    printf("|       |               |   Убывающий   | Случайный  |Возрастающий|\n");
    printf("+-------+---------------+---------------+------------+------------+\n");
    for (int i = 0; i < 5; i++) {
        testHeap(sizes[i]);
    }

    printf("\n");
    printf("Трудоемкость пирамидальной сортировки\n");
        printf("+-------+---------------+---------------+---------------+\n");
        printf("|   N   |         HeapSort(М_факт+С_факт)               |\n");
        printf("+       |---------------+---------------+---------------+\n");
        printf("|       |   Убывающий   |    Случайный  |  Возрастающий |\n");
        printf("+-------+---------------+---------------+---------------+\n");
        for (int i = 0; i<5; i++) {
                int n = sizes[i];
                int arr[n], arr_copy[n], arr_reverse[n];
                int theoretical = calcTheoretic(n);
        
                // Убывающий массив
                generateReverseSortedArray(arr_reverse, n);
                int comparisons_rev, swaps_rev;
                HeapSort(arr_reverse, n, &comparisons_rev, &swaps_rev);
                int checksum_rev = calculateChecksum(arr_reverse, n);
                printf("|  %d \t|\t%d\t|\t", n, comparisons_rev + swaps_rev);
        
                // Случайный массив
                generateRandomArray(arr, n);
                int comparisons_rand, swaps_rand;
                HeapSort(arr, n, &comparisons_rand, &swaps_rand);
                int checksum_rand = calculateChecksum(arr, n);
                printf("%d\t|\t", comparisons_rand + swaps_rand);
        
                // Возрастающий массив
                generateSortedArray(arr_copy, n);
                int comparisons_sorted, swaps_sorted;
                HeapSort(arr_copy, n, &comparisons_sorted, &swaps_sorted);
                int checksum_sorted = calculateChecksum(arr_copy, n);
                printf("%d\t|\n", comparisons_sorted + swaps_sorted);
                printf("+-------+---------------+---------------+---------------+\n");
        }
    return 0;
}

//gcc 2.c -o 2 -lm