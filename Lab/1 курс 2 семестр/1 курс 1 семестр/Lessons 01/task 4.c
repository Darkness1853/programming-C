#include <stdio.h>
#include <math.h>

int main()
{
    double x = 0.5;//Вещественные числа. Для переменных, представляющих число с плавающей точкой, используется тип Double.
    double result = sqrt(x); // Измените тип переменной result на double
    printf("The square root of %.1f is %.6f\n", x, result); // %f для double     
    //%.5f нужно чтобы поставить запятую перед 5-ю цифрами
    return 0;
}
//-lm для компоновки (линковки) математической библиотеки
