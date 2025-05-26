#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Использование: %s <имя_файла_с_матрицей>\n", argv[0]);
        return 1;
    }

    Matrix* matrix = read_matrix_from_file(argv[1]);
    if (matrix == NULL) {
        return 1;
    }

    // Проверка, что матрица квадратная
    if (!is_matrix_square(matrix)) {
        printf("Ошибка: матрица должна быть квадратной\n");
        free_matrix(matrix);
        return 1;
    }

    // Создание матрицы для обратной матрицы
    Matrix* inverse = create_matrix(matrix->rows, matrix->cols);
    if (inverse == NULL) {
        printf("Ошибка: не удалось создать матрицу для обратной\n");
        free_matrix(matrix);
        return 1;
    }

    if (!inverse_matrix(matrix, inverse)) {
        printf("Ошибка: невозможно вычислить обратную матрицу \n");
        free_matrix(matrix);
        free_matrix(inverse);
        return 1;
    }

    printf("Исходная матрица:\n");
    print_matrix(matrix);

    printf("\nОбратная матрица:\n");
    print_matrix(inverse);

    // Проверка: умножение исходной матрицы на обратную должно дать единичную матрицу
    Matrix* identity = create_matrix(matrix->rows, matrix->cols);
    if (identity == NULL) {
        printf("Ошибка: не удалось создать матрицу для проверки\n");
        free_matrix(matrix);
        free_matrix(inverse);
        return 1;
    }

    if (!multiply_matrices(matrix, inverse, identity)) {
        printf("Ошибка: не удалось проверить результат\n");
        free_matrix(matrix);
        free_matrix(inverse);
        free_matrix(identity);
        return 1;
    }

    Matrix* true_identity = create_identity_matrix(matrix->rows);
    if (true_identity == NULL) {
        printf("Ошибка: не удалось создать единичную матрицу для проверки\n");
        free_matrix(matrix);
        free_matrix(inverse);
        free_matrix(identity);
        return 1;
    }

    printf("\nРезультат умножения исходной матрицы на обратную:\n");
    print_matrix(identity);

    if (are_matrices_equal(identity, true_identity, 1e-6)) {
        printf("\nПроверка пройдена: произведение матриц равно единичной матрице\n");
    } else {
        printf("\nПредупреждение: произведение матриц не точно равно единичной матрице\n");
    }

    // Освобождение памяти
    free_matrix(matrix);
    free_matrix(inverse);
    free_matrix(identity);
    free_matrix(true_identity);

    return 0;
}