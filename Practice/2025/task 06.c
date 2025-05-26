#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для классического двоичного поиска
int binarySearch1(int arr[], int n, int target, int *comparisons) {
    int left = 0, right = n - 1;
    *comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        if (arr[mid] == target) {
            return mid; // Элемент найден
        }
        (*comparisons)++;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Элемент не найден
}

// Функция для оптимизированного двоичного поиска
int binarySearch2(int arr[], int n, int target, int *comparisons) {
    int left = 0, right = n - 1;
    *comparisons = 0;

    while (left < right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    (*comparisons)++;
    if (arr[right] == target) {
        return right; // Элемент найден
    }
    return -1; // Элемент не найден
}

void selectSort(int arr[], int n, int *swaps, int *comparisons) {
    *swaps = 0;
    *comparisons = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            (*swaps)++;
        }
    }
}

// Функция для генерации случайного массива
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }
}

int main() {
    srand(time(NULL)); 

    int sizes[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}; // Размеры массивов
    printf("+----------Трудоемкость двоичного поиска элемента-------+\n");
    printf("+-------+-----------------------+-----------------------+\n");
    printf("|   n   |      С_ф версия I     |     С_ф версия II     |\n");
    printf("+-------+-----------------------+-----------------------+\n");

    for (int i = 0; i < 10; i++) {
        int n = sizes[i];
        int arr[n];
        generateRandomArray(arr, n);
        
        int swaps = 0, sort_comparisons = 0;
        selectSort(arr, n, &swaps, &sort_comparisons); 

        int target = arr[rand() % n]; 

        int comparisons1 = 0, comparisons2 = 0;

        binarySearch1(arr, n, target, &comparisons1);
        binarySearch2(arr, n, target, &comparisons2);

        printf("| %5d | %10d\t\t| %10d\t\t|\n", n, comparisons1, comparisons2);
        printf("+-------+-----------------------+-----------------------+\n");
    }

    return 0;
}