#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Выбор ввода 
//сортировать каждую строку  по  возрастанию.  
//Определить, есть ли в матрице нули и посчитать
//найти среднее арифметическое элементов матриц.  
//Поменять местами главную и побочную диагонали.
// Способ ввода матрицы
void enter(int **matrix, int n) {
    int e;
    printf("Введите способ ввода в матрицу (С клавиатуры (0) / С рандома (1)): ");
    scanf("%d", &e);
    if (e != 0 && e != 1) {
        printf("Ошибка, неверный ввод числа\n");
        exit(999999);
    if (e %1 ==0);
        printf("Было введена буква или символ");
        exit(1);
    }
    if (e == 0) {
        printf("Был выбран ввод с помощью клавиатуры.\n");
        // Ввод элементов матрицы с клавиатуры
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("Введите число для элемента [%d][%d]: ", i, j);
                if (scanf("%d", &matrix[i][j]) !=1){
                printf("Вы ввели символ.");
                exit(-1);
                }        
            }
        }
    } else { //ввод с помощью рандома
        printf("Был выбран ввод с помощью рандома.\n");
        srand(time(NULL)); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rand() % 50; 
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
}

// Вычисление среднего арифметического и подсчет нулей
float calculate_average(int **matrix, int n) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
            if (matrix[i][j] == 0) {
                count++; 
            }
        }
    }
    printf("Количество нулей в матрице: %d\n", count);
    return (float)sum / (n * n); // Вычисляем среднее арифметическое
}

// Меняем главную с побочной диагональю
void swap(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[i][n - 1 - i];
        matrix[i][n - 1 - i] = temp;
    }
}

// Сортировка способом пузыря
void bubble_sort_row(int *row, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                int tmp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = tmp;
            }
        }
    }
}

// Сортировка матрицы
void sort_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        bubble_sort_row(matrix[i], n);
    }
}

int main() {
    int n;
    printf("Введите размер матрицы nxn: ");
    if (scanf("%d", &n)<= 0) {
        printf("Ошибка: размер матрицы должен быть положительным целым числом.\n");
        return -1;
    }
    if (n % 1 != 0) {
        printf("Необходимо ввести число, а не символ.");
        return -1;
    }
    // Выделение памяти под матрицу
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    enter(matrix, n);
    sort_matrix(matrix, n);
    float average = calculate_average(matrix, n);
    printf("Среднее арифметическое элементов матрицы: %.2f\n", average);
    swap(matrix, n);

    
    printf("Матрица после смены диагоналей и сортировки:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
    
    return 0;
}