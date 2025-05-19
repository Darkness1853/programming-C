#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matrix.h"

// Создание матрицы
Matrix* create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return NULL;
    }

    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    if (matrix == NULL) {
        return NULL;
    }

    matrix->rows = rows;
    matrix->cols = cols;

    matrix->data = (double**)malloc(rows * sizeof(double*));
    if (matrix->data == NULL) {
        free(matrix);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (double*)malloc(cols * sizeof(double));
        if (matrix->data[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

// Освобождение памяти матрицы
void free_matrix(Matrix* matrix) {
    if (matrix == NULL) {
        return;
    }

    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Чтение матрицы из файла
Matrix* read_matrix_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return NULL;
    }

    int rows, cols;
    if (fscanf(file, "%d %d", &rows, &cols) != 2) {
        printf("Ошибка: неверный формат файла\n");
        fclose(file);
        return NULL;
    }

    Matrix* matrix = create_matrix(rows, cols);
    if (matrix == NULL) {
        printf("Ошибка: не удалось создать матрицу\n");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%lf", &matrix->data[i][j]) != 1) {
                printf("Ошибка: неверные данные в файле\n");
                free_matrix(matrix);
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return matrix;
}

// Печать матрицы
void print_matrix(const Matrix* matrix) {
    if (matrix == NULL) {
        printf("Матрица не существует\n");
        return;
    }

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%8.4f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Проверка, является ли матрица квадратной
int is_matrix_square(const Matrix* matrix) {
    if (matrix == NULL) {
        return 0;
    }
    return matrix->rows == matrix->cols;
}

// Создание единичной матрицы
Matrix* create_identity_matrix(int size) {
    Matrix* matrix = create_matrix(size, size);
    if (matrix == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix->data[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    return matrix;
}

// Копирование матрицы
Matrix* copy_matrix(const Matrix* matrix) {
    if (matrix == NULL) {
        return NULL;
    }

    Matrix* copy = create_matrix(matrix->rows, matrix->cols);
    if (copy == NULL) {
        return NULL;
    }

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            copy->data[i][j] = matrix->data[i][j];
        }
    }

    return copy;
}

// Вычисление обратной матрицы методом Гаусса
int inverse_matrix(Matrix* matrix, Matrix* inverse) {
    if (matrix == NULL || inverse == NULL || matrix->rows != matrix->cols || 
        inverse->rows != inverse->cols || matrix->rows != inverse->rows) {
        return 0;
    }

    int n = matrix->rows;
    double temp;

    // Присоединяем единичную матрицу справа
    Matrix* augmented = create_matrix(n, 2 * n);
    if (augmented == NULL) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented->data[i][j] = matrix->data[i][j];
            augmented->data[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    //  метод Гаусса
    for (int i = 0; i < n; i++) {
        // Если элемент на диагонали равен 0, ищем строку для замены
        if (fabs(augmented->data[i][i]) < 1e-10) {
            int swap_row = -1;
            for (int k = i + 1; k < n; k++) {
                if (fabs(augmented->data[k][i]) > 1e-10) {
                    swap_row = k;
                    break;
                }
            }

            if (swap_row == -1) {
                free_matrix(augmented);
                return 0; // Матрица вырожденная(квадратная матрица, которая не имеет обратной матрицы.)
            }

            // Меняем строки местами
            for (int j = 0; j < 2 * n; j++) {
                temp = augmented->data[i][j];
                augmented->data[i][j] = augmented->data[swap_row][j];
                augmented->data[swap_row][j] = temp;
            }
        }

        // Нормализуем текущую строку
        temp = augmented->data[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmented->data[i][j] /= temp;
        }

        // Обнуляем элементы ниже текущего
        for (int k = i + 1; k < n; k++) {
            temp = augmented->data[k][i];
            for (int j = 0; j < 2 * n; j++) {
                augmented->data[k][j] -= augmented->data[i][j] * temp;
            }
        }
    }

    // Обратный ход метода Гаусса
    for (int i = n - 1; i >= 0; i--) {
        for (int k = i - 1; k >= 0; k--) {
            temp = augmented->data[k][i];
            for (int j = 0; j < 2 * n; j++) {
                augmented->data[k][j] -= augmented->data[i][j] * temp;
            }
        }
    }

    // Копируем обратную матрицу из расширенной
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse->data[i][j] = augmented->data[i][j + n];
        }
    }

    free_matrix(augmented);
    return 1;
}

// Умножение матриц
int multiply_matrices(const Matrix* a, const Matrix* b, Matrix* result) {
    if (a == NULL || b == NULL || result == NULL || 
        a->cols != b->rows || result->rows != a->rows || result->cols != b->cols) {
        return 0;
    }

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->data[i][j] = 0.0;
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return 1;
}

// Проверка равенства матриц с заданной точностью
int are_matrices_equal(const Matrix* a, const Matrix* b, double epsilon) {
    if (a == NULL || b == NULL || a->rows != b->rows || a->cols != b->cols) {
        return 0;
    }

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            if (fabs(a->data[i][j] - b->data[i][j]) > epsilon) {
                return 0;
            }
        }
    }

    return 1;
}