#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <time.h>

// Версия 1
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

// Версия 2
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
        return right; 
    }
    return -1; 
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

int binary_Search(wchar_t *s, wchar_t target, int *comparisons) {
    int n = wcslen(s);
    if (n == 0) return -1;

    int left = 0, right = n - 1;
    *comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        if (s[mid] == target) {
            return mid; 
        }
        (*comparisons)++;
        if (s[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    setlocale(LC_ALL, "");
    int choice;
    printf("Выберите вариант:\n");
    printf("1. Двоичный поиск в массиве (классический)\n");
    printf("2. Двоичный поиск в массиве (оптимизированный)\n");
    printf("3. Двоичный поиск в строке\n");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) {
        printf("Вы выбрали вариант %d. Двоичный поиск в массиве.\n", choice);
        int arr[] = {7, 4, 3, 8, 1, 5, 4, 2};
        int n = sizeof(arr) / sizeof(arr[0]);

        qsort(arr, n, sizeof(int), compare);

        int comparisons;
        srand(time(0));
        int randomIndex = rand() % n;
        int target = arr[randomIndex];

        printf("Отсортированный массив: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        int checksum_before = calculate_checksum(arr, n);
        int series_before = count_series(arr, n);

        int result;
        if (choice == 1) {
            result = binarySearch1(arr, n, target, &comparisons);
        } else {
            result = binarySearch2(arr, n, target, &comparisons);
        }

        if (result != -1) {
            printf("Элемент %d найден на позиции %d\n", target, result + 1);
        } else {
            printf("Элемент %d не найден\n", target);
        }

        printf("Количество сравнений: %d\n", comparisons);
        printf("Контрольная сумма до поиска: %d\n", checksum_before);
        printf("Число серий до поиска: %d\n", series_before);
    } else if (choice == 3) {
        wprintf(L"Вы выбрали вариант 3. Двоичный поиск в строке.\n");
        wchar_t str[] = L"НГУЕНЗУЙ";
        wchar_t target = L'У'; 
        int comparisons;

        int result = binary_Search(str, target, &comparisons);

        if (result != -1) {
            wprintf(L"Символ '%lc' найден на позиции %d\n", target, result);
        } else {
            wprintf(L"Символ '%lc' не найден\n", target);
        }

        printf("Количество сравнений: %d\n", comparisons);
    } else {
        printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
    }

    return 0;
}