# Программирование на C: 
# Конспекты за 1-2 семестр

## 1 семестр

### 1. Языки программирования и их типы.
**Типы языков**:
- Компилируемые (C, C++)
- Интерпретируемые (Python, JavaScript)
- Гибридные (Java, C#)
  
[Ссылка на доп. материал](https://habr.com/ru/articles/539784/)

**Пример на C**:
```c
#include <stdio.h>
int main() {
    printf("Hello, world!");
    return 0;
}
```

### 2. Архитектура и микроархитектура
**Архитектура** (x86, ARM) - набор команд процессора.  
**Микроархитектура** - реализация архитектуры (Intel Core, AMD Ryzen).

[Ссылка на доп. материал](https://ru.wikipedia.org/wiki/%D0%9C%D0%B8%D0%BA%D1%80%D0%BE%D0%B0%D1%80%D1%85%D0%B8%D1%82%D0%B5%D0%BA%D1%82%D1%83%D1%80%D0%B0)

### 3. Компиляция и первая программа.
**Этапы компиляции**:
1. Препроцессинг (`gcc -E`)
2. Компиляция (`gcc -S`)
3. Ассемблирование (`gcc -c`)
4. Линковка (`gcc`)

[Ссылка на доп. материал](https://metanit.com/c/tutorial/3.1.php)
**Пример**:
```c
// hello.c
#include <stdio.h>
int main() {
    printf("Hello, World!\n");
    return 0;
}
```
Компиляция с помощью: `gcc hello.c -o hello`

### 4. Типы данных и вывод.
Классификация данных, которые может обрабатывать программа.

[Ссылка на доп. материал](https://younglinux.info/c/printf)
**Базовые типы**:
```c
int age = 20;           // Целое
float pi = 3.14f;       // С плавающей точкой
char letter = 'A';      // Символ
```
### 5. Операторы и условия.
Конструкции для развлетвления логики программы.

[Ссылка на доп. материал](https://metanit.com/c/tutorial/2.7.php)
**Пример условий**:
```c
int x = 10;
if (x > 5) {
    printf("x больше чем 5\n");
} else {
    printf("x равен 5 или меньше\n");
}
```

### 6. Циклы.
Повторение блока кода.

[Ссылка на доп. материал](ttps://prog-cpp.ru/c-cycles/)
**Пример for**:
```c
for (int i = 0; i < 5; i++) {
    printf("%d ", i);
}
```
Вывод программы: ` 0 1 2 3 4`
### 7. Битовые операции.
Работа с данными на уровне битов.

[Ссылка на доп. материал](https://proproprogs.ru/c_base/c_bitovye-operacii-i-ili-ne-xor-sdvigovye-operacii)
```c
unsigned char a = 0b1010;  // 10
unsigned char b = 0b1100;  // 12
unsigned char c = a & b;   // 0b1000 (8)
```

### 8. Массивы и указатели.
Хранение наборов данных и работа с адресами памяти.

[Ссылка на доп. материал](https://metanit.com/c/tutorial/5.5.php)
```c
int arr[3] = {1, 2, 3};
int *ptr = arr;
printf("%d", *ptr);  // 1
```

### 9. Функции и препроцессор.
Обработка кода перед компиляцией.

[Ссылка на доп. материал](https://prog-cpp.ru/c-directives/)
**Макрос**:
```c
#define SQUARE(x) ((x)*(x))
printf("%d", SQUARE(5));  // 25
```

### 10. Структуры данных.
Пользовательские составные типы данных.

[Ссылка на доп. материал](https://metanit.com/c/tutorial/6.1.php)
```c
typedef struct {
    int x;
    int y;
} Point;

Point p = {10, 20};
```

### 11. Отладка.
Отладчик - (англ. debugger от bug, баг) — компьютерная программа для отладки: поиска ошибок в программах.
В зависимости от встроенных возможностей, отладчик позволяет выполнять трассировку, отслеживать, устанавливать или изменять значения переменных в процессе выполнения кода,
устанавливать и удалять точки останова или условия остановки, выводить стек и кадры функций, перемещаться между потоками в многопоточной программе и т.д. 

[Ссылка на github моего преподавателя](https://github.com/kruffka/C-Programming/blob/master/2024-2025/debug_gdb_valgrind/8_GDB.md)

**GDB команды**:
```
sudo apt install gdb -y // Установка gdb
gdb
break main    // Установка точки останова
run          // Запуск программы
print x      // Печать переменной
```

### 12. Многофайловые проекты.

[Ссылка на доп. материал](https://younglinux.info/c/multifile)
**Структура**:
```
project/
├── main.c
├── utils.h
└── utils.c
```
Компиляция: `gcc main.c utils.c -o app`

## 2 семестр.

### 1. Алгоритмы и списки.

[Ссылка на доп. материал](https://tproger.ru/translations/linked-list-for-beginners)
**Связный список**:
```c
struct Node {
    int data;
    struct Node* next;
};
```

### 2. Работа с файлами.

[Ссылка на доп. материал](https://itproger.com/course/c-programming/9#:~:text=%D0%97%D0%B0%20%D1%81%D1%87%D1%91%D1%82%20%D1%8F%D0%B7%D1%8B%D0%BA%D0%B0%20%D0%A1%D0%B8%20%D0%B2%D1%8B%20%D0%BC%D0%BE%D0%B6%D0%B5%D1%82%D0%B5%20%D1%81%20%D0%BB%D0%B5%D0%B3%D0%BA%D0%BE%D1%81%D1%82%D1%8C%D1%8E,%D0%BA%D0%BB%D0%B0%D1%81%D1%81%D1%8B%20%D0%B4%D0%BB%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%8B%20%D1%81%20%D1%84%D0%B0%D0%B9%D0%BB%D0%B0%D0%BC%D0%B8%20%D0%B8%20%D0%B4%D0%B8%D1%80%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D1%8F%D0%BC%D0%B8%20%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82%D0%B0.)
**Чтение файла**:
```c
FILE *f = fopen("file.txt", "r");
char buffer[100];
fgets(buffer, 100, f);
fclose(f);
```

### 3. Библиотеки.
**Создание статической библиотеки**:

[Ссылка на доп. материал](https://younglinux.info/c/library)
```bash
gcc -c lib.c -o lib.o
ar rcs lib.a lib.o
```

### 4. Git и GitHub.

[Документация из GitHub](https://docs.github.com/ru/get-started/learning-to-code/getting-started-with-git)
[Ссылка на мой файл с командами для управления GitHub]()
**Основные команды**:
```bash
git init
git add .
git commit -m "Initial commit"
git push origin main
```

### 5. Многопоточность (POSIX).

[Ссылка на доп. материал](https://habr.com/ru/articles/881444/)
[Ссылка на мой файл с командами для управления GitHub]()
```c
#include <pthread.h>
void* thread_func(void* arg) {
    printf("Hello from thread!\n");
    return NULL;
}
pthread_t thread;
pthread_create(&thread, NULL, thread_func, NULL);
```

### 6. Тестирование.
**Пример unit-теста**:

[Ссылка на доп. материал](https://habr.com/ru/articles/244835/)
```c
void test_addition() {
    assert(2+2 == 4);
}

