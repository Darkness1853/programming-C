#include <stdio.h>
#include <string.h>
#include <locale.h>

void HeapSort(char arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        char temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        HeapSort(arr, n, largest);
    }
}

void heapSort(char arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapSort(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        char temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        HeapSort(arr, i, 0);
    }
}

int main() {
    setlocale(LC_ALL, ""); 
    
    char fio[] = "NGUENZUYANKY";
    int n = strlen(fio); 

    printf("Исходный массив:\n");
    for (int i = 0; i < n; i++)
        printf("%c ", fio[i]);
    printf("\n");

    heapSort(fio, n);

    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++)
        printf("%c ", fio[i]);
    printf("\n");

    return 0;
}