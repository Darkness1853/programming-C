#include "matrix.h"
#include <math.h>
#include <string.h>

Matrix* create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return NULL;
    }

    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    if (!matrix) {
        return NULL;
    }

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double**)malloc(rows * sizeof(double*));
    if (!matrix->data) {
        free(matrix);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (double*)malloc(cols * sizeof(double));
        if (!matrix->data[i]) {
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
double calculate_determinant(const Matrix* matrix) {
    if (!matrix || matrix->rows != matrix->cols) {
        fprintf(stderr, "Error: Matrix must be square to calculate determinant\n");
        return 0.0; // Ноль как признак ошибки
    }

    int n = matrix->rows;
    
    // Для матрицы 1x1
    if (n == 1) {
        return matrix->data[0][0];
    }
    
    // Для матрицы 2x2
    if (n == 2) {
        return matrix->data[0][0] * matrix->data[1][1] - 
               matrix->data[0][1] * matrix->data[1][0];
    }
    
    // Для матриц 3x3 и больше
    double det = 0.0;
    Matrix* submatrix = create_matrix(n-1, n-1);
    
    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                submatrix->data[subi][subj] = matrix->data[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix->data[0][x] * calculate_determinant(submatrix);
    }
    
    free_matrix(submatrix);
    return det;
}
void free_matrix(Matrix* matrix) {
    if (matrix) {
        for (int i = 0; i < matrix->rows; i++) {
            free(matrix->data[i]);
        }
        free(matrix->data);
        free(matrix);
    }
}

Matrix* read_matrix_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    int rows = 0, cols = 0;
    char line[1024];

    // First pass to determine dimensions
    while (fgets(line, sizeof(line), file)) {
        rows++;
        char* token = strtok(line, " \t\n");
        int current_cols = 0;
        while (token) {
            current_cols++;
            token = strtok(NULL, " \t\n");
        }
        if (rows == 1) {
            cols = current_cols;
        } else if (current_cols != cols) {
            fprintf(stderr, "Error: Inconsistent number of columns in row %d\n", rows);
            fclose(file);
            return NULL;
        }
    }

    if (rows != cols) {
        fprintf(stderr, "Error: Matrix is not square (%dx%d), cannot compute inverse\n", rows, cols);
        fclose(file);
        return NULL;
    }

    // Rewind file and create matrix
    rewind(file);
    Matrix* matrix = create_matrix(rows, cols);
    if (!matrix) {
        fclose(file);
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }

    // Second pass to read data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%lf", &matrix->data[i][j]) != 1) {
                fprintf(stderr, "Error: Invalid matrix element at (%d,%d)\n", i+1, j+1);
                free_matrix(matrix);
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return matrix;
}

void print_matrix(const Matrix* matrix) {
    if (!matrix) {
        printf("Matrix is NULL\n");
        return;
    }

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%.6f\t", matrix->data[i][j]);
        }
        printf("\n");
    }
}

bool is_matrix_invertible(const Matrix* matrix) {
    if (!matrix || matrix->rows != matrix->cols) {
        return false;
    }

    int n = matrix->rows;
    Matrix* temp = create_matrix(n, n);
    if (!temp) {
        return false;
    }

    // Copy matrix to temp
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp->data[i][j] = matrix->data[i][j];
        }
    }

    // Perform Gaussian elimination to check if matrix is invertible
    for (int i = 0; i < n; i++) {
        // Partial pivoting
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(temp->data[k][i]) > fabs(temp->data[max_row][i])) {
                max_row = k;
            }
        }

        // Swap rows if needed
        if (max_row != i) {
            for (int k = 0; k < n; k++) {
                double tmp = temp->data[i][k];
                temp->data[i][k] = temp->data[max_row][k];
                temp->data[max_row][k] = tmp;
            }
        }

        // If diagonal element is zero, matrix is not invertible
        if (fabs(temp->data[i][i]) < 1e-12) {
            free_matrix(temp);
            return false;
        }

        // Eliminate other rows
        for (int k = i + 1; k < n; k++) {
            double factor = temp->data[k][i] / temp->data[i][i];
            for (int j = i; j < n; j++) {
                temp->data[k][j] -= factor * temp->data[i][j];
            }
        }
    }

    free_matrix(temp);
    return true;
}

Matrix* inverse_matrix(const Matrix* matrix) {
    if (!matrix || matrix->rows != matrix->cols || !is_matrix_invertible(matrix)) {
        return NULL;
    }

    int n = matrix->rows;
    Matrix* inverse = create_matrix(n, n);
    Matrix* temp = create_matrix(n, 2 * n);
    if (!inverse || !temp) {
        free_matrix(inverse);
        free_matrix(temp);
        return NULL;
    }

    // Initialize augmented matrix [A|I]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp->data[i][j] = matrix->data[i][j];
            temp->data[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Gaussian elimination to get [I|A^-1]
    for (int i = 0; i < n; i++) {
        // Partial pivoting
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(temp->data[k][i]) > fabs(temp->data[max_row][i])) {
                max_row = k;
            }
        }

        // Swap rows if needed
        if (max_row != i) {
            for (int k = 0; k < 2 * n; k++) {
                double tmp = temp->data[i][k];
                temp->data[i][k] = temp->data[max_row][k];
                temp->data[max_row][k] = tmp;
            }
        }

        // Normalize current row
        double pivot = temp->data[i][i];
        for (int k = 0; k < 2 * n; k++) {
            temp->data[i][k] /= pivot;
        }

        // Eliminate other rows
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = temp->data[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    temp->data[k][j] -= factor * temp->data[i][j];
                }
            }
        }
    }

    // Extract inverse matrix from the right half
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse->data[i][j] = temp->data[i][j + n];
        }
    }

    free_matrix(temp);
    return inverse;
}

Matrix* multiply_matrices(const Matrix* a, const Matrix* b) {
    if (!a || !b || a->cols != b->rows) {
        return NULL;
    }

    Matrix* result = create_matrix(a->rows, b->cols);
    if (!result) {
        return NULL;
    }

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->data[i][j] = 0.0;
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return result;
}

bool are_matrices_equal(const Matrix* a, const Matrix* b, double tolerance) {
    if (!a || !b || a->rows != b->rows || a->cols != b->cols) {
        return false;
    }

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            if (fabs(a->data[i][j] - b->data[i][j]) > tolerance) {
                return false;
            }
        }
    }

    return true;
}