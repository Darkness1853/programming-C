#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

void print_step(wchar_t arr[], int index, int k) {
    for (int i = 0; i < wcslen(arr); i++) {
        if (i == index || i == k) {
            printf("[%lc] ", arr[i]); // Обозначаем текущий и минимальный элементы квадратными скобками
        } else {
            printf("%lc ", arr[i]);
        }
    }
    printf("\n"); 
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

        print_step(s, i, k);

        // Обмен местами
        if (k != i) {
            wchar_t temp = s[i];
            s[i] = s[k];
            s[k] = temp;

        }
    }

    printf("Отсортированная строка: %ls\n", s); 
}

int main() {
    setlocale(LC_ALL, "");

    wchar_t str[] = L"НГУЕНЗУЙ"; 
    my_sort(str);
    return 0;
}