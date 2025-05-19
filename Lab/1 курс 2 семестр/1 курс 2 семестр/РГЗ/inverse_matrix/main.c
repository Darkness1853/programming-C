#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <matrix_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Matrix* matrix = read_matrix_from_file(argv[1]);
    if (!matrix) {
        return EXIT_FAILURE;
    }
   double det = calculate_determinant(matrix);
    printf("Determinant: %.6f\n", det);

    if (fabs(det) < 1e-12) {
        fprintf(stderr, "Error: Matrix is not invertible (determinant is zero)\n");
        free_matrix(matrix);
        return EXIT_FAILURE;
    }

    Matrix* inverse = inverse_matrix(matrix);
    if (!inverse) {
        fprintf(stderr, "Error: Failed to compute inverse matrix\n");
        free_matrix(matrix);
        return EXIT_FAILURE;
    }

    printf("Original matrix:\n");
    print_matrix(matrix);

    printf("\nInverse matrix:\n");
    print_matrix(inverse);

    // Verification: multiply matrix by its inverse should give identity matrix
    Matrix* product = multiply_matrices(matrix, inverse);
    if (product) {
        printf("\nVerification (should be identity matrix):\n");
        print_matrix(product);
        free_matrix(product);
    }

    free_matrix(matrix);
    free_matrix(inverse);
    return EXIT_SUCCESS;
}