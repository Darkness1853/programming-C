#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertSort(int arr[], int n, int *swaps, int *comparisons) {
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

void ShellSort(int arr[], int n, int *swaps, int *comparisons) {
    int i, j, step;
    int tmp;
    *swaps = 0; 
    *comparisons = 0; 

    for (step = 10; step > 0; step /= 2) {
        for (i = step; i < n; i++) {
            tmp = arr[i];
            (*swaps)++;
            for (j = i; j >= step; j -= step) {
                (*comparisons)++;
                if (tmp < arr[j - step]) {
                    arr[j] = arr[j - step];
                    (*swaps)++;
                } else {
                    break;
                }
            }
            arr[j] = tmp;
            (*swaps)++;
        }
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }
}

int calculateChecksum(int arr[], int n) {
    int checksum = 0;
    for (int i = 0; i < n; i++) {
        checksum += arr[i];
    }
    return checksum;
}

int main() {
    srand(time(NULL)); 

    int sizes[] = {100, 200, 300, 400, 500};
    printf("+-------+-------------------------------+---------------------------------------+-------------------------------+\n");
    printf("|   N   | h1 … hm по формуле Д.Кнута    |      Insert  М_ф+С_ф                  |       Shell  M_ф+С_ф          |\n");
    printf("+-------+-------------------------------+---------------------------------------+-------------------------------+\n");

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int arr1[n], arr2[n];
        generateRandomArray(arr1, n);
        generateRandomArray(arr2, n);

        int swapsShell = 0, comparisonsShell = 0;
        int swapsInsert = 0, comparisonsInsert = 0;

        ShellSort(arr1, n, &swapsShell, &comparisonsShell);
        insertSort(arr2, n, &swapsInsert, &comparisonsInsert);
        printf("| %5d | ", n);
        // Шаги по формуле Кнута
        int steps[100]; 
        int stepCount = 0; 

        int h = 1;
        while (h < n / 3) {
            steps[stepCount++] = h; 
            h = 3 * h + 1;
        }
        steps[stepCount++] = h; 

        for (int i = 0; i < stepCount; i++) {
            printf("%d ", steps[i]);
        }
        printf(" \t\t| %10d (M=%d, C=%d) \t| %10d (M=%d, C=%d) |\t\n",
               swapsInsert + comparisonsInsert, swapsInsert, comparisonsInsert,
               swapsShell + comparisonsShell, swapsShell, comparisonsShell);
    }

    printf("+-------+-------------------------------+---------------------------------------+-------------------------------+\n");
    return 0;
}
