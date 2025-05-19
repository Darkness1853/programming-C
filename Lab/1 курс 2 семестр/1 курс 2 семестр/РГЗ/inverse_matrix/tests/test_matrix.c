#include "matrix.h"
#include <assert.h>
#include <stdio.h>

void test_matrix_creation() {
    Matrix* m = create_matrix(3, 3);
    assert(m != NULL);
    assert(m->rows == 3);
    assert(m->cols == 3);
    free_matrix(m);
    printf("test_matrix_creation passed\n");
}

void test_matrix_inversion() {
    double data[3][3] = {
        {4, 7, 2},
        {3, 5, 1},
        {6, 8, 9}
    };
    
    Matrix* m = create_matrix(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m->data[i][j] = data[i][j];
        }
    }
    
    Matrix* inv = inverse_matrix(m);
    assert(inv != NULL);
    
    Matrix* product = multiply_matrices(m, inv);
    assert(product != NULL);
    
    // Create identity matrix for comparison
    Matrix* identity = create_matrix(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            identity->data[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    
    assert(are_matrices_equal(product, identity, 1e-6));
    
    free_matrix(m);
    free_matrix(inv);
    free_matrix(product);
    free_matrix(identity);
    printf("test_matrix_inversion passed\n");
}

void test_non_invertible_matrix() {
    double data[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    Matrix* m = create_matrix(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m->data[i][j] = data[i][j];
        }
    }
    
    assert(!is_matrix_invertible(m));
    assert(inverse_matrix(m) == NULL);
    
    free_matrix(m);
    printf("test_non_invertible_matrix passed\n");
}

int main() {
    test_matrix_creation();
    test_matrix_inversion();
    test_non_invertible_matrix();
    return 0;
}