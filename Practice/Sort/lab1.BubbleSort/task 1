#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>

void bubbleSortWithCounts(int arr[], int n, int *M, int *C) {
    *M = 0; // Количество пересылок
    *C = 0; // Количество сравнений

    for (int i = 0; i < n - 1; i++) {
        int k = i;

        for (int j = i + 1; j < n; j++) {
            (*C)++; // Увеличиваем счетчик сравнений
            if (arr[j] < arr[k]) {
                k = j;
            }
        }

        // Обмен местами
        if (k != i) {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            (*M)++; // Увеличиваем счетчик пересылок
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

void bubble_sortnumb(int *arr, int n) {
    if (n == 0) return; 

    printf("Исходный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                // Меняем местами элементы
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }

            for (int k = 0; k < n; k++) {
                if (k < i) {
                    printf("\033[30m%d\033[0m ", arr[k]); // Черный
                } else if (k == j || k == j - 1) {
                    printf("\033[4m%d\033[0m ", arr[k]); // Подчеркнутый
                } else {
                    printf("\033[30m%d\033[0m ", arr[k]); // Черный
                }
            }
            printf("\n");
        }

        // Текущий статус сортировки
        for (int k = 0; k < n; k++) {
            printf(k < i + 1 ? "\033[34m%d\033[0m " : "\033[30m%d\033[0m ", arr[k]); // Синий
        }
        printf("\n");
    }

    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void bubble_sort(wchar_t *s) {
    int n = wcslen(s);
    if (n == 0) return;

    wchar_t temp;
    wprintf(L"%ls\n", s);
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (s[j] < s[j - 1]) {
                // Меняем местами символы
                temp = s[j];
                s[j] = s[j - 1];
                s[j - 1] = temp;
            }

            for (int k = 0; k < n; k++) {
                if (k < i) {
                    wprintf(L"\033[30m%lc\033[0m", s[k]); // Черный
                } else if (k == j || k == j - 1) {
                    wprintf(L"\033[4m%lc\033[0m", s[k]); // Подчеркнутый
                } else {
                    wprintf(L"\033[30m%lc\033[0m", s[k]); // Черный
                }
            }
            wprintf(L"\n");
        }
        
        for (int k = 0; k < n; k++) {
            wprintf(k < i + 1 ? L"\033[34m%lc\033[0m" : L"\033[30m%lc\033[0m", s[k]); // Синий
        }
        wprintf(L"\n");
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

        bubbleSortWithCounts(arr, n, &M, &C);
        bubble_sortnumb(arr, n);
        printf("\n");

        int checksum_after = calculate_checksum(arr, n);
        int series_after = count_series(arr, n);

        printf("Контрольная сумма до сортировки: %d\n", checksum_before);
        printf("Контрольная сумма после сортировки: %d\n", checksum_after);
        printf("Число серий до сортировки: %d\n", series_before);
        printf("Число серий после сортировки: %d\n", series_after);
        printf("Фактическое количество пересылок: %d\n", M);
        printf("Фактическое количество сравнений: %d\n", C);

        int theoretical_M = n - 1; // Максимальное количество пересылок
        int theoretical_C = n * (n - 1) / 2; // Максимальное количество сравнений
        printf("Теоретическое количество пересылок: %d\n", theoretical_M);
        printf("Теоретическое количество сравнений: %d\n", theoretical_C);
    } else if (choice == 2) { 
        wprintf(L"Вы выбрали вариант 2. Сортировка букв.\n");
        wchar_t str[] = L"НГУЕНЗУЙ"; 
        bubble_sort(str);
    } else {
        printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
    }

    return 0;
}