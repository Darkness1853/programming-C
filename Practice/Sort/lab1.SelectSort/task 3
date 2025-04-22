#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT1 10
#define COUNT2 100

void selectSort(int arr[], int n, int *swaps, int *comparisons) {
    *swaps = 0;
    *comparisons = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        if (k != i) {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            (*swaps) += 3; 
        }
    }
}

void selectSort_upgrade(int arr[], int n, int *swaps, int *comparisons) {
    *swaps = 0;
    *comparisons = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        int min_value = arr[i]; 
        
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < min_value) {
                min_index = j;
                min_value = arr[j]; 
            }
        }
        
        // Перестановка только если нашли новый минимум
        if (min_index != i) {
            arr[min_index] = arr[i]; 
            arr[i] = min_value;
            (*swaps) += 2; 
        }
    }
}

void generateTestArrays(int reverse[], int random[], int sorted[], int n) {
    for (int i = 0; i < n; i++) {
        reverse[i] = n - i;
        random[i] = rand() % 1000;
        sorted[i] = i + 1;
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void printResults(int n, int teoret, int swaps_normal[], int comps_normal[], int swaps_up[], int comps_up[]) {
    printf("| %3d | %13d | %6d | %6d | %6d | %6d | %6d | %6d |\n", 
           n, teoret,
           swaps_normal[0]+comps_normal[0], 
           swaps_normal[1]+comps_normal[1], 
           swaps_normal[2]+comps_normal[2],
           swaps_up[0]+comps_up[0], 
           swaps_up[1]+comps_up[1], 
           swaps_up[2]+comps_up[2]);
}

int main() {
    srand(time(NULL));

    printf("-----------------------Трудоемкость метода прямого выбора--------------------\n");
    printf("+-----+---------------+--------+--------+--------+--------+--------+--------+\n");
    printf("|  N  | M+C теоретич. | Исходный M_факт+C_факт   | Улучшенный M_факт+C_факт |\n");
    printf("|     |               +--------+--------+--------+--------+--------+--------+\n");
    printf("|     |               |  Убыв. |  Случ. |  Возр. |  Убыв. |  Случ. |  Возр. |\n");
    printf("+-----+---------------+--------+--------+--------+--------+--------+--------+\n");


    {
        int n = COUNT1;
        int reverse[n], random[n], sorted[n];
        generateTestArrays(reverse, random, sorted, n);
        
        // Массивы для обычной сортировки
        int arr1[n], arr2[n], arr3[n];
        copyArray(reverse, arr1, n);
        copyArray(random, arr2, n);
        copyArray(sorted, arr3, n);
        
        // Массивы для улучшенной сортировки
        int arr4[n], arr5[n], arr6[n];
        copyArray(reverse, arr4, n);
        copyArray(random, arr5, n);
        copyArray(sorted, arr6, n);
        
        int swaps_normal[3], comps_normal[3];
        int swaps_up[3], comps_up[3];
        
        selectSort(arr1, n, &swaps_normal[0], &comps_normal[0]);
        selectSort(arr2, n, &swaps_normal[1], &comps_normal[1]);
        selectSort(arr3, n, &swaps_normal[2], &comps_normal[2]);
        
        selectSort_upgrade(arr4, n, &swaps_up[0], &comps_up[0]);
        selectSort_upgrade(arr5, n, &swaps_up[1], &comps_up[1]);
        selectSort_upgrade(arr6, n, &swaps_up[2], &comps_up[2]);
        
        int teoret = (3*(n - 1)) + (n*n - n)/2;
        printResults(n, teoret, swaps_normal, comps_normal, swaps_up, comps_up);
        printf("+-----+---------------+--------+--------+--------+--------+--------+--------+\n");
    }

    {
        int n = COUNT2;
        int reverse[n], random[n], sorted[n];
        generateTestArrays(reverse, random, sorted, n);
        
        // Массивы для обычной сортировки
        int arr1[n], arr2[n], arr3[n];
        copyArray(reverse, arr1, n);
        copyArray(random, arr2, n);
        copyArray(sorted, arr3, n);
        
        // Массивы для улучшенной сортировки
        int arr4[n], arr5[n], arr6[n];
        copyArray(reverse, arr4, n);
        copyArray(random, arr5, n);
        copyArray(sorted, arr6, n);
        
        int swaps_normal[3], comps_normal[3];
        int swaps_up[3], comps_up[3];
        
        selectSort(arr1, n, &swaps_normal[0], &comps_normal[0]);
        selectSort(arr2, n, &swaps_normal[1], &comps_normal[1]);
        selectSort(arr3, n, &swaps_normal[2], &comps_normal[2]);
        
        selectSort_upgrade(arr4, n, &swaps_up[0], &comps_up[0]);
        selectSort_upgrade(arr5, n, &swaps_up[1], &comps_up[1]);
        selectSort_upgrade(arr6, n, &swaps_up[2], &comps_up[2]);
        
        int teoret = (3*(n - 1)) + (n*n - n)/2;
        printResults(n, teoret, swaps_normal, comps_normal, swaps_up, comps_up);
        printf("+-----+---------------+--------+--------+--------+--------+--------+--------+\n");
    }

    return 0;
}