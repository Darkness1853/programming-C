// Структура дроби
struct fraction {
    int numerator;   // числитель
    int denominator; // знаменатель
};

// Функции работы с дробями
struct fraction createFraction(int numerator, int denominator);
struct fraction fractionsXfractions(struct fraction f1, struct fraction f2);
struct fraction divisionFractions(struct fraction f1, struct fraction f2);
void printFraction(struct fraction frac);
