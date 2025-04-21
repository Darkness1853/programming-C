#include <stdio.h>
#include "func_arr.h"

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Исходный массив: ");
    print_array(arr, size);

    printf("Максимальный элемент: %d\n", find_max(arr, size));
    printf("Минимальный элемент: %d\n", find_min(arr, size));

    bubble_sort(arr, size);
    printf("Отсортированный массив: ");
    print_array(arr, size);

    return 0;
}