#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>

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

int calculate_checksum(int arr[], int n) {
    int checksum = 0;
    for (int i = 0; i < n; i++) {
        checksum += arr[i];
    }
    return checksum;
}

int count_series(int arr[], int n) {
    int series_count = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            series_count++;
        }
    }
    return series_count + 1; 
}

void shaker_sort_int(int *arr, int n) {
    if (n == 0) return; 

    printf("Исходный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int M, C;
    insertSort(arr, n, &M, &C); 

    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Число пересылок: %d\n", M);
    printf("Число сравнений: %d\n", C);
}

void insert_Sort_wchar(wchar_t *s) {
    int n = wcslen(s);
    if (n == 0) return; 
    int M = 0, C = 0;
    wchar_t temp;
    wprintf(L"Исходная строка:\n%ls\n", s);
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) { 
            (M++);
            if (s[j - 1] > s[j]) {
                int tmp = s[j - 1];
                s[j - 1] = s[j];
                s[j] = tmp;
                (C++);
            } else {
                break; 
            }
            }
        }
    wprintf(L"Отсортированная строка:\n%ls\n", s);
    printf("Число пересылок: %d\n", M);
    printf("Число сравнений: %d\n", C);
}

int main() {
    setlocale(LC_ALL, "");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) { 
        printf("Вы выбрали вариант 1. Сортировка цифр.\n");
        int arr[] = {7,4,3,8,1,5,4,2};
        int n = sizeof(arr) / sizeof(arr[0]);
        int M, C;

        printf("Исходный массив: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        int checksum_before = calculate_checksum(arr, n);
        int series_before = count_series(arr, n);

        insertSort(arr, n, &M, &C);

        printf("Отсортированный массив: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        int checksum_after = calculate_checksum(arr, n);
        int series_after = count_series(arr, n);

        printf("Контрольная сумма до сортировки: %d\n", checksum_before);
        printf("Контрольная сумма после сортировки: %d\n", checksum_after);
        printf("Число серий до сортировки: %d\n", series_before);
        printf("Число серий после сортировки: %d\n", series_after);
        printf("Фактическое количество пересылок: %d\n", M);
        printf("Фактическое количество сравнений: %d\n", C);

        int theoretical_M = n * (n - 1) / 2; // Максимальное количество пересылок
        int theoretical_C = n * (n - 1); // Максимальное количество сравнений
        printf("Теоретическое количество пересылок: %d\n", theoretical_M);
        printf("Теоретическое количество сравнений: %d\n", theoretical_C);
    } else if (choice == 2) { 
        wprintf(L"Вы выбрали вариант 2. Сортировка букв.\n");
        wchar_t str[] = L"НГУЕНЗУЙ"; 
        insert_Sort_wchar(str);
    } else {
        printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
    }

    return 0;
}