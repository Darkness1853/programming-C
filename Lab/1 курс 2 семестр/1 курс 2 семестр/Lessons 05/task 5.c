#include <stdio.h>
#include <string.h>

typedef struct {
    char surname[50];
    char name[50];
    char zodiac[50];
    int birthday[3]; 
} Person;

void createFile() {
    FILE *file = fopen("Znak.dat", "wb");
    Person people[] = {
        {"Иванов", "Алексей", "Овен", {12, 4, 1990}},
        {"Петрова", "Мария", "Телец", {25, 4, 1985}},
        {"Сидоров", "Дмитрий", "Близнецы", {5, 6, 1992}},
        {"Попов", "Матвей", "Рак", {17, 7, 1994}},
        {"Нгуен", "Зуй-Ань", "Овен", {9, 4, 1998}},
        {"Добромилов", "Артём", "Весы", {23, 9, 1991}},
        {"Дроздова", "Мария", "Водолей", {11, 2, 1989}}
    };
    fwrite(people, sizeof(Person),7 , file);
    fclose(file);
}

void printPerson(Person p) {
    printf("\nФамилия: %s\nИмя: %s\nЗнак: %s\nДата: %02d.%02d.%d\n",
           p.surname, p.name, p.zodiac, p.birthday[0], p.birthday[1], p.birthday[2]);
}

void searchInFile() {
    FILE *file = fopen("Znak.dat", "rb");
    if (!file) return;

    Person p;
    int choice, found = 0;
    char search[50];
    
    printf("\nПоиск по:\n1-Фамилия\n2-Имя\n3-Знак\n4-Дата\nВыбор: ");
    scanf("%d", &choice);

    printf("Введите значение: ");
    if (choice == 4) {
        int day, month, year;
        scanf("%d %d %d", &day, &month, &year);
        while (fread(&p, sizeof(Person), 1, file)) {
            if (p.birthday[0] == day && p.birthday[1] == month && p.birthday[2] == year) {
                printPerson(p);
                found = 1;
            }
        }
    } else {
        scanf("%s", search);
        while (fread(&p, sizeof(Person), 1, file)) {  
            if (choice == 1 && strcmp(p.surname, search)==0) {
                printPerson(p);
                found = 1;
            }
            else if (choice == 2 && strcmp(p.name, search)==0) {
                printPerson(p);
                found = 1;
            }
            else if (choice == 3 && strcmp(p.zodiac, search)==0) {
                printPerson(p);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("Не найдено\n");
    }
    fclose(file);
}

int main() {
    createFile();
    char answer = 'y';  
    while (answer == 'y' || answer == 'Y') {
    searchInFile();
    printf("Продолжить? (y/n): ");
    scanf(" %c", &answer);
}
    return 0;
}