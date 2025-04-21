#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>

// Функция для сортировки массива чисел
void print_step(int arr[], int n, int index, int k) {
    for (int i = 0; i < n; i++) {
        if (i == index || i == k) {
            printf("[%d] ", arr[i]); // Обозначаем текущий и минимальный элементы
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void selectSort(int arr[], int n, int *M, int *C) {
    *M = 0;
    *C = 0; 

    for (int i = 0; i < n - 1; i++) {
        int k = i;

        for (int j = i + 1; j < n; j++) {
            (*C)++; 
            if (arr[j] < arr[k]) {
                k = j;
            }
        }

        print_step(arr, n, i, k);

        if (k != i) {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            (*M)++; 
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
    if (n == 0) return 0;
    int series_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            series_count++;
        }
    }
    return series_count;
}

// Функция для сортировки строки
void print_step_str(wchar_t arr[], int index, int k) {
    for (int i = 0; i < wcslen(arr); i++) {
        if (i == index || i == k) {
            wprintf(L"[%lc]", arr[i]); // Без пробелов внутри []
        } else {
            wprintf(L"%lc", arr[i]);
        }
    }
    wprintf(L"\n");
}

void my_sort(wchar_t s[]) {
    int n = wcslen(s);

    for (int i = 0; i < n - 1; i++) {
        int k = i;

        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[k]) {
                k = j;
            }
        }

        print_step_str(s, i, k);

        if (k != i) {
            wchar_t temp = s[i];
            s[i] = s[k];
            s[k] = temp;
        }
    }

    wprintf(L"Отсортированная строка: %ls\n", s); 
}

int main() {
    setlocale(LC_ALL, "");
    int choice;

    printf("Выберите вариант (1 - числа, 2 - строка): ");
    if (scanf("%d", &choice) != 1) {
        printf("Ошибка: введите число 1 или 2!\n");
        return 1;
    }

    if (choice == 1) {
        printf("Сортировка чисел\n");
        int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
        int n = sizeof(arr) / sizeof(arr[0]);
        int M, C;

        printf("Исходный массив: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        int checksum_before = calculate_checksum(arr, n);
        int series_before = count_series(arr, n);

        selectSort(arr, n, &M, &C);

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

        int theoretical_M = n - 1;
        int theoretical_C = n * (n - 1) / 2;
        printf("Теоретическое количество пересылок: %d\n", theoretical_M);
        printf("Теоретическое количество сравнений: %d\n", theoretical_C);
    } else if (choice == 2) {
        wprintf(L"Сортировка строки\n");
        wchar_t str[] = L"НГУЕНЗУЙ"; 
        wprintf(L"Исходная строка: %ls\n", str);
        my_sort(str);
    } else {
        printf("Неверный выбор. Введите 1 или 2.\n");
    }

    return 0;
}