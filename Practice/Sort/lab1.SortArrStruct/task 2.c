#include <stdio.h>
#include <string.h>

typedef struct {
    char last_name[50];   // фамилия
    char first_name[50];  // имя
    char middle_name[50]; // отчество
    char phone[15];       // телефон
} Subscriber;

// Флаг для обратного порядка
int reverse_order = 0;

// Сравнение по имени
int lessByName(const Subscriber *x, const Subscriber *y) {
    int cmp = strcmp(x->first_name, y->first_name);
    if (reverse_order) {
        return cmp > 0;
    } else {
        return cmp < 0;
    }
}

// Сравнение по номеру телефона
int lessByPhone(const Subscriber *x, const Subscriber *y) {
    int cmp = strcmp(x->phone, y->phone);
    if (reverse_order) {
        return cmp > 0;
    } else {
        return cmp < 0;
    }
}

// Сравнение по фамилии и отчеству
int lessByLastNameAndMiddleName(const Subscriber *x, const Subscriber *y) {
    int surname_cmp = strcmp(x->last_name, y->last_name);
    
    if (surname_cmp != 0) {
        if (reverse_order) {
            return surname_cmp > 0;
        } else {
            return surname_cmp < 0;
        }
    }
    
    int middle_cmp = strcmp(x->middle_name, y->middle_name);
    if (reverse_order) {
        return middle_cmp > 0;
    } else {
        return middle_cmp < 0;
    }
}

void InsertSort(Subscriber *dir, int size, int (*less)(const Subscriber*, const Subscriber*)) {
    for (int i = 1; i < size; i++) {
        Subscriber temp = dir[i];
        int j = i - 1;
        
        while (j >= 0 && less(&dir[j], &temp)) {
            dir[j + 1] = dir[j];
            j--;
        }
        dir[j + 1] = temp;
    }
}

void printDirectory(const Subscriber *dir, int size) {
    printf("\n+------------------Телефонный справочник------------------+\n");
    if (reverse_order) {
        printf("| Направление: Обратный порядок (Я-А)                     |\n");
    } else {
        printf("| Направление: Прямой порядок (А-Я)                       |\n");
    }
    printf("+---------------+---------------+---------------+---------+\n");
    printf("|Фамилия\t|  Имя\t\t|Отчество       |Телефон  |\n");
    printf("+---------------+---------------+---------------+---------+\n");
    
    if (reverse_order) {
        for (int i = size-1; i >= 0; i--) {
            printf("|%-15s\t| %-15s\t|%-15s\t|%s|\n", 
                   dir[i].last_name, 
                   dir[i].first_name, 
                   dir[i].middle_name,
                   dir[i].phone);
            printf("+---------------+---------------+---------------+---------+\n");
        }
    } else {
        for (int i = 0; i < size; i++) {
            printf("|%-15s\t| %-15s\t|%-15s\t|%s|\n", 
                   dir[i].last_name, 
                   dir[i].first_name, 
                   dir[i].middle_name,
                   dir[i].phone);
            printf("+---------------+---------------+---------------+---------+\n");
        }
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
    
    int choice;
    do {
        printf("\nМеню:\n");
        printf("1 - Сортировать по имени\n");
        printf("2 - Сортировать по телефону\n");
        printf("3 - Сортировать по фамилии и отчеству\n");
        printf("4 - Показать в обратном порядке\n");
        printf("5 - Показать в прямом порядке\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                InsertSort(directory, size, lessByName);
                printf("\nОтсортировано по имени:");
                printDirectory(directory, size);
                break;
            case 2:
                InsertSort(directory, size, lessByPhone);
                printf("\nОтсортировано по телефону:");
                printDirectory(directory, size);
                break;
            case 3:
                InsertSort(directory, size, lessByLastNameAndMiddleName);
                printf("\nОтсортировано по фамилии и отчеству:");
                printDirectory(directory, size);
                break;
            case 4:
                reverse_order = 1;
                printf("\nСправочник в обратном порядке:");
                printDirectory(directory, size);
                break;
            case 5:
                reverse_order = 0;
                printf("\nСправочник в прямом порядке:");
                printDirectory(directory, size);
                break;
        }
    } while (choice != 0);
    
    return 0;
}