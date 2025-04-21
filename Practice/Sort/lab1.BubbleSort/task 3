#include <stdio.h>

void bubble_sort(int *arr, int n) {
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

int main() {
    int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubble_sort(arr, n);

    return 0;
}