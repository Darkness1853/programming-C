#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>

void ShellSort(int arr[], int n, int *M, int *C) {
    int i, j, step;
    int tmp;
    *M = 0;
    *C = 0; 

    // Последовательность шагов: h = 2, h = 1
    for (step = 2; step > 0; step /= 2) {
        for (i = step; i < n; i++) {
            tmp = arr[i];
            (*M)++;
            for (j = i; j >= step; j -= step) {
                (*C)++;
                if (tmp < arr[j - step]) {
                    arr[j] = arr[j - step];
                    (*M)++;
                } else {
                    break;
                }
            }
            arr[j] = tmp;
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
    int series_count = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            series_count++;
        }
    }
    return series_count + 1;
}

void shell_sort(wchar_t *s) {
    int n = wcslen(s);
    if (n == 0) return; 
    wchar_t temp;
    int step;

    // Последовательность шагов: h = 2, h = 1
    for (step = 2; step > 0; step /= 2) {
        for (int i = step; i < n; i++) {
            temp = s[i];
            int j;
            for (j = i; j >= step && s[j - step] > temp; j -= step) {
                s[j] = s[j - step];
            }
            s[j] = temp;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) { 
        printf("Вы выбрали вариант 1. Сортировка цифр.\n");
        int arr[] = {5, 3, 8, 6, 2, 7, 4, 8};
        int n = sizeof(arr) / sizeof(arr[0]);
        int M, C;

        printf("Исходный массив: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        int checksum_before = calculate_checksum(arr, n);
        int series_before = count_series(arr, n);

        ShellSort(arr, n, &M, &C);

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

        int theoretical_M = n * n; // Теоретическое количество пересылок
        int theoretical_C = n * n; // Теоретическое количество сравнений
        printf("Теоретическое количество пересылок: %d\n", theoretical_M);
        printf("Теоретическое количество сравнений: %d\n", theoretical_C);
    } else if (choice == 2) { 
        wprintf(L"Вы выбрали вариант 2. Сортировка букв.\n");
        wchar_t str[] = L"НГУЕНЗУЙ";
        shell_sort(str);
        wprintf(L"Отсортированная строка: %ls\n", str);
    } else {
        printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
    }

    return 0;
}