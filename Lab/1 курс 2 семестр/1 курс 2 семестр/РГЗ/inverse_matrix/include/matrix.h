#ifndef MATRIX_H
#define MATRIX_H
#include <math.h>

// Структура для хранения матрицы
typedef struct {
    double** data;
    int rows;
    int cols;
} Matrix;

// Функции для работы с матрицами
Matrix* create_matrix(int rows, int cols);
void free_matrix(Matrix* matrix);
Matrix* read_matrix_from_file(const char* filename);
void print_matrix(const Matrix* matrix);
int is_matrix_square(const Matrix* matrix);
Matrix* create_identity_matrix(int size);
int inverse_matrix(Matrix* matrix, Matrix* inverse);
Matrix* copy_matrix(const Matrix* matrix);
int multiply_matrices(const Matrix* a, const Matrix* b, Matrix* result);
int are_matrices_equal(const Matrix* a, const Matrix* b, double epsilon);

#endif 