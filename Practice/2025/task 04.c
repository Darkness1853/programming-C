#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

void print_step(int arr[], int n, int index, int k) {
    for (int i = 0; i < n; i++) {
        if (i == index || i == k) {
            printf("[%d] ", arr[i]); // Обозначаем текущий и минимальный элементы квадратными скобками
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void selectSort(int arr[], int n, int *M, int *C) {
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

        print_step(arr, n, i, k);

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
    return series_count + 1; // +1 для последней серии
}

int main() {
    setlocale(LC_ALL, "");

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

    // Теоретические оценки
    int theoretical_M = n - 1; // Максимальное количество пересылок
    int theoretical_C = n * (n - 1) / 2; // Максимальное количество сравнений

    printf("Теоретическое количество пересылок: %d\n", theoretical_M);
    printf("Теоретическое количество сравнений: %d\n", theoretical_C);

    return 0;
}