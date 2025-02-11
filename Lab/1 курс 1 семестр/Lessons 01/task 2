#include <stdio.h>
#include <limits.h> // Для пределов типов
//Переменные типа int способны хранить целые числа примерно в диапазоне от
// -2 миллиарда до +2 миллиарда .
//Получаем максимальные значения для `int` и `unsigned int` с
//помощью предопределенных `INT_MAX` и `UINT_MAX`.
//`unsigned` не имеет отрицательных значений.
int main() {
    // Для int
    int max = INT_MAX; // Максимальное значение для int
    printf("Максимальное значение для int: %d\n", max);

    int over = max + 1; // Добавляем 1
    printf("Результат maxInt + 1: %d\n", over); // Печатаем результат

    // Для unsigned int
    unsigned int maxUT = UINT_MAX; // Максимальное значение для unsigned int    printf("Максимальное значение для unsigned int: %u\n", maxUT);

    unsigned int over1 = maxUT + 1; // Добавляем 1
    printf("Результат maxUnsignedInt + 1: %u\n", over1); // Печатаем резуль>//signed char           От -128 до 127
//unsigned char         От 0 до 255
    // Для char
    char minChar = CHAR_MIN; // Минимальное значение для char
    printf("Минимальное значение для char: %d\n", (int)minChar); // Печатае>

    char overflowChar = minChar - 1; // Вычитаем 1
    printf("Результат minChar - 1: %d\n", (int)overflowChar); // Печатаем р>

    return 0;
}
