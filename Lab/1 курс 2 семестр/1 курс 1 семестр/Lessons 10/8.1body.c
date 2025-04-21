#include <stdio.h>
#include "8.1call.h"

// Функция для создания дроби
struct fraction createFraction(int numerator, int denominator) {
    struct fraction frac;
    frac.numerator = numerator;
    frac.denominator = denominator;
    return frac;
}

// Функция для умножения дробей
struct fraction fractionsXfractions(struct fraction f1, struct fraction f2) {
    struct fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    return result;
}

// Функция для деления дробей
struct fraction divisionFractions(struct fraction f1, struct fraction f2) {
    struct fraction result;
    if (f2.numerator == 0) {
        printf("Ошибка: Делить на ноль нельзя!\n");
    } else {
        result.numerator = f1.numerator * f2.denominator;
        result.denominator = f1.denominator * f2.numerator;
    }
    return result;
}

// Функция для вывода дроби
void printFraction(struct fraction frac) {
    printf("%d/%d\n", frac.numerator, frac.denominator);
}