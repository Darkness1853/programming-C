#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int A[], int n);
void FillDec(int A[], int n);
void FillRand(int A[], int n);
int CheckSum(int A[], int n);
int RunNumber(int A[], int n);
void PrintMassive(int A[], int n);


// заполнение массива возрастающими числами
void FillInc(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = i + 1; // от 1 до n
    }
}

// заполнение массива убывающими числами
void FillDec(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = n - i; // от n до 1
    }
}

// заполнение массива случайными числами
void FillRand(int A[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 101; // случайные числами от 0 до 100
    }
}

// подсчет контрольной суммы элементов массива
int CheckSum(int A[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

// подсчета серий в массиве
int RunNumber(int A[], int n) {
    int seriesCount = 1; 
    for (int i = 1; i < n; i++) {
        if (A[i] < A[i-1]) {
            seriesCount++;
        }
    }
    return seriesCount;
}

// вывод элементов массива
void PrintMassive(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int n = 10; // размер массива
    int A[n];

    // возрастающие числа
    FillInc(A, n);
    printf("Возрастающий массив чисел:\n");
    PrintMassive(A, n);
    printf("Количество серий в возростающем: %d\n", RunNumber(A, n));
    printf("Контрольная сумма: %d\n", CheckSum(A, n));

    // убывающие числа
    FillDec(A, n);
    printf("Убывающий массив чисел:\n");
    PrintMassive(A, n);
    printf("Количество серий в убывающем: %d\n", RunNumber(A, n));
    printf("Контрольная сумма: %d\n", CheckSum(A, n));

    // случайные числа
    FillRand(A, n);
    printf("Случайный массив чисел:\n");
    PrintMassive(A, n);
    printf("Контрольная сумма: %d\n", CheckSum(A, n));
    printf("Количество серий в случайном массиве: %d\n", RunNumber(A, n));

    return 0;
}
