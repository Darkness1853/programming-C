#include <stdio.h>

int main()
{
    float x, f;
    char c; 
    
    printf("Введите число, означающее температуру, и затем символ 'c' либо 'f': ");
    scanf("%f %c", &x, &c);

    if (c == 'c' || c == 'C')
    {
        f = (x * 1.8) + 32;
        printf("Фаренгейт: %f\n", f);
    }
    else if (c == 'f' || c == 'F')
    {
        x = (x - 32) / 1.8;
        printf("Цельсия: %f\n", x);
    }
    else
    {
        printf("Output error.\nUse 'c' for Celsius or 'f' for Fahrenheit.\n");
    }

    return 0; 
}
