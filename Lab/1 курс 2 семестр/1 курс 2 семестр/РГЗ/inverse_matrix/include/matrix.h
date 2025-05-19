#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    double** data;
    int rows;
    int cols;
} Matrix;
double calculate_determinant(const Matrix* matrix);
Matrix* create_matrix(int rows, int cols);
void free_matrix(Matrix* matrix);
Matrix* read_matrix_from_file(const char* filename);
void print_matrix(const Matrix* matrix);
bool is_matrix_invertible(const Matrix* matrix);
Matrix* inverse_matrix(const Matrix* matrix);
Matrix* multiply_matrices(const Matrix* a, const Matrix* b);
bool are_matrices_equal(const Matrix* a, const Matrix* b, double tolerance);

#endif 