#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char last_name[50];    // Фамилия
    char first_name[50];   // Имя
    char middle_name[50];  // Отчество
    char phone[15];        // Телефон
} Subscriber;

// Функция сравнения для сортировки по фамилии
int LessLastName(const void *a, const void *b) {
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    const Subscriber *subA = (const Subscriber *)ia;
    const Subscriber *subB = (const Subscriber *)ib;
    return strcmp(subA->last_name, subB->last_name);
}

// Функция сравнения для сортировки по отчеству
int LessMidName(const void *a, const void *b) {
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    const Subscriber *subA = (const Subscriber *)ia;
    const Subscriber *subB = (const Subscriber *)ib;
    return strcmp(subA->middle_name, subB->middle_name);
}

void InsertSort(int *index, Subscriber *dir, int size, int (*compare)(const void *, const void *)) {
    for (int i = 1; i < size; i++) {
        int temp = index[i];
        int j = i - 1;
        
        while (j >= 0 && compare(&dir[index[j]], &dir[temp]) > 0) {
            index[j + 1] = index[j];
            j--;
        }
        index[j + 1] = temp;
    }
}

void printIndexArr(int indexArr[], int size, const char* words) {
    printf("Индексный массив %s:\n", words);
    for (int i = 0; i < size; i++) {
        printf("%d ", indexArr[i]);
    }
    printf("\n\n");
}
// Функция вывода справочника с использованием индексного массива
void printDirectIndex(Subscriber *dir, int *index, int size, const char *sortField) {
    printf("\nСправочник, %s:\n", sortField);
    printf("+---------------+---------------+---------------+-----------------------+\n");
    printf("| Фамилия       | Имя           | Отчество      | Телефон               |\n");
    printf("+---------------+---------------+---------------+-----------------------+\n");
    
    for (int i = 0; i < size; i++) {
        printf("| %-14s\t| %-14s\t| %-14s\t| %-15s\t|\n", 
               dir[index[i]].last_name, 
               dir[index[i]].first_name, 
               dir[index[i]].middle_name,
               dir[index[i]].phone);
               printf("+---------------+---------------+---------------+-----------------------+\n");
    }
}

int main() {
    Subscriber directory[] = {
        {"Иванов", "Алексей", "Сергеевич", "111-22-33"},
        {"Петров", "Вадим", "Александрович", "555-44-33"},
        {"Сидоров", "Роман", "Петрович", "777-77-77"},
        {"Кузнецов", "Иван", "Николаевич", "123-45-67"},
        {"Попов", "Сергей", "Владимирович", "321-65-49"}
    };
    
    int size = sizeof(directory) / sizeof(directory[0]);
    
    // Создаем индексные массивы
    int IndexLastName[size];
    int IndexMidName[size];
    
    // Инициализируем индексные массивы
    for (int i = 0; i < size; i++) {
        IndexLastName[i] = i;
        IndexMidName[i] = i;
    }
    // Содержимое индексных массивов
    printDirectIndex(directory,IndexLastName,size,"изначальный, по фамилии");
    printIndexArr(IndexLastName, size, "по фамилии");
    printDirectIndex(directory,IndexMidName, size , "изначальный, по отчеству");
    printIndexArr(IndexMidName, size, "по отчеству");
    // Сортируем индексные массивы
    InsertSort(IndexLastName, directory, size, LessLastName);
    InsertSort(IndexMidName, directory, size, LessMidName);
    
    // Выводим справочник, отсортированный по фамилии
    printDirectIndex(directory, IndexLastName, size, "отсортированный по фамилии");
    printIndexArr(IndexLastName, size, "по фамилии");
    
    // Выводим справочник, отсортированный по отчеству
    printDirectIndex(directory, IndexMidName, size, "отсортированный по отчеству");
    printIndexArr(IndexMidName, size, "по отчеству");
    
    return 0;
}