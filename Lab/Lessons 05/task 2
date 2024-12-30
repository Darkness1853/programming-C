//второй вариант
#include<stdio.h>
int main() {
    int a;
    printf("Введите целое число: ");
    scanf("%d", &a);

    printf("Четные индексы: ");
    for (int i = 0; i < 32; i += 2) {
        printf("%d", (a >> i) & 1);
    }

    printf("\nНечетные индексы: ");
    for (int i = 1; i < 32; i += 2) {
        printf("%d", (a >> i) & 1);
    }

    return 0;
}
