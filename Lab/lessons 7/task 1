#include <stdio.h>
#include <string.h>

int main() {
    printf("Программа определяет, есть ли в заданном предложении цифры. И если есть, найдёт их сумму.\nВведите текст: ");

    char s[256];
    fgets(s, sizeof(s), stdin); 

    int l = strlen(s);
    int sum = 0; 

    for (int i = 0; i < l; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            sum += (s[i] - '0');
        }
    }

    if (sum == 0) {
        printf("К сожалению, в тексте нет чисел.\n");
    } else {
        printf("Сумма цифр: %d\n", sum);
    }

    return 0;
}