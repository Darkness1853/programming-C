#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>

void shakerSort(int* mass, int count, int *M, int *C) {
    *M = 0; 
    *C = 0; 
    int left = 0, right = count - 1; 
    int flag = 1;  
    while ((left < right) && flag > 0) {
        flag = 0;
        for (int i = left; i < right; i++) { // двигаемся слева направо
            (*C)++;
            if (mass[i] > mass[i + 1]) { // если следующий элемент меньше текущего
                (*M)++;
                int t = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = t;
                flag = 1; // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--) { // двигаемся справа налево
            (*C)++;
            if (mass[i - 1] > mass[i]) { // если предыдущий элемент больше текущего
                (*M)++;
                int t = mass[i];
                mass[i] = mass[i - 1];
                mass[i - 1] = t;
                flag = 1; 
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
        if (flag == 0) break;
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
    shakerSort(arr, n, &M, &C); 

    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Число пересылок: %d\n", M);
    printf("Число сравнений: %d\n", C);
}

void shaker_sort_wchar(wchar_t *s) {
    int n = wcslen(s);
    if (n == 0) return; 

    wchar_t temp;
    wprintf(L"Исходная строка:\n%ls\n", s);
    int M = 0, C = 0;
    int left = 0, right = n - 1;  
    int flag = 1;  

    while ((left < right) && flag > 0) {
        flag = 0;
        for (int i = left; i < right; i++) { // двигаемся слева направо
            C++;
            if (s[i] > s[i + 1]) {
                M++;
                temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--) { // двигаемся справа налево
            C++;
            if (s[i - 1] > s[i]) {
                M++;
                temp = s[i];
                s[i] = s[i - 1];
                s[i - 1] = temp;
                flag = 1;
            }
        }
        left++;
        if (flag == 0) break;
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

        shakerSort(arr, n, &M, &C);

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

        int theoretical_M = n * (n - 1) / 2; 
        int theoretical_C = n * (n - 1);
        printf("Теоретическое количество пересылок: %d\n", theoretical_M);
        printf("Теоретическое количество сравнений: %d\n", theoretical_C);
    } else if (choice == 2) { 
        wprintf(L"Вы выбрали вариант 2. Сортировка букв.\n");
        wchar_t str[] = L"НГУЕНЗУЙ"; 
        shaker_sort_wchar(str);
    } else {
        printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
    }

    return 0;
}