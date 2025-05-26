#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"
#include <math.h>

// Тест создания и освобождения матрицы
static void test_create_and_free_matrix(void** state) {
    Matrix* matrix = create_matrix(3, 3);
    assert_non_null(matrix);
    assert_int_equal(matrix->rows, 3);
    assert_int_equal(matrix->cols, 3);
    
    free_matrix(matrix);
}

// Тест проверки квадратной матрицы
static void test_is_matrix_square(void** state) {
    Matrix* square = create_matrix(2, 2);
    assert_non_null(square);
    assert_true(is_matrix_square(square));
    
    Matrix* non_square = create_matrix(2, 3);
    assert_non_null(non_square);
    assert_false(is_matrix_square(non_square));
    
    free_matrix(square);
    free_matrix(non_square);
}

// Тест создания единичной матрицы
static void test_create_identity_matrix(void** state) {
    Matrix* identity = create_identity_matrix(3);
    assert_non_null(identity);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                assert_true(fabs(identity->data[i][j] - 1.0) < 1e-10);
            } else {
                assert_true(fabs(identity->data[i][j]) < 1e-10);
            }
        }
    }
    
    free_matrix(identity);
}

// Тест копирования матрицы
static void test_copy_matrix(void** state) {
    Matrix* original = create_matrix(2, 2);
    assert_non_null(original);
    
    original->data[0][0] = 1.0;
    original->data[0][1] = 2.0;
    original->data[1][0] = 3.0;
    original->data[1][1] = 4.0;
    
    Matrix* copy = copy_matrix(original);
    assert_non_null(copy);
    
    assert_true(are_matrices_equal(original, copy, 1e-10));
    
    free_matrix(original);
    free_matrix(copy);
}

// Тест вычисления обратной матрицы
static void test_inverse_matrix(void** state) {
    Matrix* matrix = create_matrix(2, 2);
    assert_non_null(matrix);
    
    matrix->data[0][0] = 4.0;
    matrix->data[0][1] = 7.0;
    matrix->data[1][0] = 2.0;
    matrix->data[1][1] = 6.0;
    
    Matrix* inverse = create_matrix(2, 2);
    assert_non_null(inverse);
    
    assert_true(inverse_matrix(matrix, inverse));
    
    // Ожидаемая обратная матрица
    Matrix* expected_inverse = create_matrix(2, 2);
    assert_non_null(expected_inverse);
    
    expected_inverse->data[0][0] = 0.6;
    expected_inverse->data[0][1] = -0.7;
    expected_inverse->data[1][0] = -0.2;
    expected_inverse->data[1][1] = 0.4;
    
    assert_true(are_matrices_equal(inverse, expected_inverse, 1e-6));
    
    // Проверка, что произведение матрицы на обратную дает единичную матрицу
    Matrix* identity = create_matrix(2, 2);
    assert_non_null(identity);
    
    assert_true(multiply_matrices(matrix, inverse, identity));
    
    Matrix* true_identity = create_identity_matrix(2);
    assert_non_null(true_identity);
    
    assert_true(are_matrices_equal(identity, true_identity, 1e-6));
    
    free_matrix(matrix);
    free_matrix(inverse);
    free_matrix(expected_inverse);
    free_matrix(identity);
    free_matrix(true_identity);
}

// Тест для вырожденной матрицы (не должна иметь обратной)
static void test_singular_matrix(void** state) {
    Matrix* matrix = create_matrix(2, 2);
    assert_non_null(matrix);
    
    matrix->data[0][0] = 1.0;
    matrix->data[0][1] = 2.0;
    matrix->data[1][0] = 2.0;
    matrix->data[1][1] = 4.0;
    
    Matrix* inverse = create_matrix(2, 2);
    assert_non_null(inverse);
    
    assert_false(inverse_matrix(matrix, inverse));
    
    free_matrix(matrix);
    free_matrix(inverse);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_create_and_free_matrix),
        cmocka_unit_test(test_is_matrix_square),
        cmocka_unit_test(test_create_identity_matrix),
        cmocka_unit_test(test_copy_matrix),
        cmocka_unit_test(test_inverse_matrix),
        cmocka_unit_test(test_singular_matrix),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}