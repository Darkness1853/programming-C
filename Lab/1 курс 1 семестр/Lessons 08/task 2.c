//Оценка 4: реализовать алгоритм Крамера для решения СЛАУ NxN, где N может быть от 2 до 3.

#include <stdio.h>
#include <stdlib.h>
//(1,1)*(2,2)-(1,2)*(2.1)
float determinant2x2(float a, float b, float c, float d) {
    return a * d - b * c;
}
//(1,1)*((2,2)*(3,3)-(2,3)*(3,2))-(1,2)*((2,1)*(3,3)-(2,3)*(3,1))+(3,1)*((2,1)*(3,2)-(2,2)*(3,1))
float determinant3x3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33) {
    return a11 * (a22 * a33 - a23 * a32) - a12 * (a21 * a33 - a23 * a31) + a13 * (a21 * a32 - a22 * a31);
}

int main() {
    printf("Введите N=2/3, чтобы реализовать алгоритм Крамера для решения СЛАУ:\n");
    int n;
    scanf("%d", &n);

    if (n < 2 || n > 3) {
        printf("Вы ввели неправильно\n");
        return -1;
    }

    // массив 
    float *coeff = (float *)malloc(n * n * sizeof(float));
    float *results = (float *)malloc(n * sizeof(float));

    if (coeff == NULL || results == NULL) {
        printf("Ошибка в выделении памяти!\n");
        return -1;
    }

    // Ввод коэффициентов
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Введите коэффициент для уравнения (%d, %d): ", i + 1, j + 1);
            if (scanf("%f", &coeff[i * n + j]) !=1){
                printf("Ошибка! Введите число\n");
                return -1;
            }
        }
        printf("Введите свободный член для уравнения %d: ", i + 1);
            if (scanf("%f", &results[i]) !=1){
                printf("Ошибка! Введите число\n");
                return -1;
            }
    }

    if (n == 2) {
        // Коэффициенты для системы 2x2
        float a1 = coeff[0];
        float b1 = coeff[1];
        float a2 = coeff[2];
        float b2 = coeff[3];
        
        float d = determinant2x2(a1, b1, a2, b2);
        if (d == 0) {
            printf("Нет единственного решения.\n");
            free(coeff);
            free(results);coeff=NULL;
            results=NULL;
            return 0;
        }

        float x1 = (results[0] * b2 - results[1] * b1) / d;
        float x2 = (results[1] * a1 - results[0] * a2) / d;

        printf("Решение: x1 = %.2f, x2 = %.2f\n", x1, x2);

    } else if (n == 3) {
        // Коэффициенты для системы 3x3
        float a11 = coeff[0];
        float a12 = coeff[1];
        float a13 = coeff[2];
        float a21 = coeff[3];
        float a22 = coeff[4];
        float a23 = coeff[5];
        float a31 = coeff[6];
        float a32 = coeff[7];
        float a33 = coeff[8];
        
        float d = determinant3x3(a11, a12, a13, a21, a22, a23, a31, a32, a33);
        if (d == 0) {
            printf("Нет единственного решения.\n");
            free(coeff);
            free(results);
            coeff=NULL;
            results=NULL;
            return 0;
        }

        float d1 = determinant3x3(results[0], a12, a13, results[1], a22, a23, results[2], a32, a33);
        float d2 = determinant3x3(a11, results[0], a13, a21, results[1], a23, a31, results[2], a33);
        float d3 = determinant3x3(a11, a12, results[0], a21, a22, results[1], a31, a32, results[2]);

        float x1 = d1 / d;
        float x2 = d2 / d;
        float x3 = d3 / d;

        printf("Решение: x1 = %.2f, x2 = %.2f, x3 = %.2f\n", x1, x2, x3);
    }

    // Освобождаем память
    free(coeff);
    free(results);
    coeff=NULL;
    results=NULL;


    return 0;
}