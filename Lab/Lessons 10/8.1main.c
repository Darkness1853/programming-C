#include <stdio.h>
#include "8.1call.h"

int main() {
    int choice, numerator, denominator;

    printf("Введите: \n1, чтобы умножить дробь \n2, чтобы разделить дробь\n");
    scanf("%d", &choice);

    printf("Введите числитель: ");
    scanf("%d", &numerator);
    printf("Введите знаменатель: ");
    scanf("%d", &denominator);

    struct fraction frac1 = createFraction(numerator, denominator);
    struct fraction frac2;

    if (choice == 1) {
        printf("Введите числитель второй дроби: ");
        scanf("%d", &numerator);
        printf("Введите знаменатель второй дроби: ");
        scanf("%d", &denominator);
        frac2 = createFraction(numerator, denominator);

        struct fraction multiplicationResult = fractionsXfractions(frac1, frac2);
        printf("Результат умножения: ");
        printFraction(multiplicationResult);
    } else if (choice == 2) {
        printf("Введите числитель второй дроби: ");
        scanf("%d", &numerator);
        printf("Введите знаменатель второй дроби: ");
        scanf("%d", &denominator);
        frac2 = createFraction(numerator, denominator);

        struct fraction divisionResult = divisionFractions(frac1, frac2);
        printf("Результат деления: ");
        printFraction(divisionResult);
    } else {
        printf("Некорректный выбор операции.\n");
    }
    return 0;
}