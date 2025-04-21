#include <stdio.h>
//на 3
// Структура для дроби
struct fraction {
    int numerator;   // числитель
    int denominator; // знаменатель
};

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
        result.numerator = 0;
        result.denominator = 1; 
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