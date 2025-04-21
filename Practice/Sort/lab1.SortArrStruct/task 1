#include <stdio.h>
#include <string.h>

typedef struct {
    char last_name[50];   // фамилия
    char first_name[50];  // имя
    char middle_name[50]; // отчество
    char phone[15];       // телефон
} Subscriber;

// Сравнение по имени
int lessByName(const Subscriber *x, const Subscriber *y) {
    if (strcmp(x->first_name, y->first_name) < 0) {
        return 1;
    }
    return 0;
}

// Сравнение по номеру телефона
int lessByPhone(const Subscriber *x, const Subscriber *y) {
    if (strcmp(x->phone, y->phone) < 0) {
        return 1;
    }
    return 0;
}

// Сравнение по фамилии и отчеству 
int LessLastNameAndMiddleName(const Subscriber *x, const Subscriber *y) {
    int surname_cmp = strcmp(x->last_name, y->last_name);
    
    if (surname_cmp < 0) {
        return 1;
    }
    else if (surname_cmp > 0) {
        return 0;
    }
    
    if (strcmp(x->middle_name, y->middle_name) < 0) {
        return 1;
    }
    return 0;
}
// Универсальная функция сортировки вставками
void InsertSort(Subscriber *dir, int size, int (*less)(const Subscriber*, const Subscriber*)) {
    for (int i = 1; i < size; i++) {
        Subscriber temp = dir[i];
        int j = i - 1;
        
        while (j >= 0 && less(&temp, &dir[j])) {
            dir[j + 1] = dir[j];
            j--;
        }
        dir[j + 1] = temp;
    }
}

void printDirectory(const Subscriber *dir, int size) {
    printf("\n+------------------Телефонный справочник------------------+\n");
    printf("+---------------+---------------+---------------+---------+\n");
    printf("|Фамилия\t|  Имя\t\t|Отчество       |Телефон  |\n");
    printf("+---------------+---------------+---------------+---------+\n");
    
    for (int i = 0; i < size; i++) {
        printf("|%-15s\t| %-15s\t|%-15s\t|%s|\n", 
               dir[i].last_name, 
               dir[i].first_name, 
               dir[i].middle_name,
               dir[i].phone);
        printf("+---------------+---------------+---------------+---------+\n");
    }
}

int main() {
    Subscriber directory[] = {
        {"Иванов", "Алексей", "Сергеевич", "111-22-33"},
        {"Петров", "Вадим", "Александрович", "555-44-33"},
        {"Нгуен", "Зуй-Ань", "Куеевич", "123-45-67"},
        {"Петров", "Роман", "Юрьевич", "777-77-77"},
        {"Погорелов", "Владислав", "Александрович", "321-65-49"}
    };
    
    int size = sizeof(directory) / sizeof(directory[0]);
    
    printf("Исходный справочник:");
    printDirectory(directory, size);
    
    // Сортировка по имени
    InsertSort(directory, size, lessByName);
    printf("\nОтсортированный по имени:");
    printDirectory(directory, size);
    
    // Сортировка по номеру телефона
    InsertSort(directory, size, lessByPhone);
    printf("\nОтсортированный по номеру телефона:");
    printDirectory(directory, size);
    
    // Сортировка по фамилии и отчеству
    InsertSort(directory, size, LessLastNameAndMiddleName);
    printf("\nОтсортированный по фамилии и отчеству:");
    printDirectory(directory, size);
    
    return 0;
}