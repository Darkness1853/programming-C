<!-- vscode-markdown-toc -->
* 1. [Лабораторная работа №7: Знакомство с POSIX потоками](#Лабораторная-работа-7-Знакомство-с-POSIX-потоками)
	* 1.1. [На оценку 3](#На-оценку-3)
		* 1.1.1. [Тема: Первое знакомство с pthread](#Тема-Первое-знакомство-с-pthread)
		* 1.1.2. [Цель работы](#Цель-работы)
		* 1.1.3. [Процесс](#Процесс)
	* 1.2. [На оценку 4](#На-оценку-4)
		* 1.2.1. [Тема: Перемножение матриц](#Тема-Перемножение-матриц)
		* 1.2.2. [Цель работы](#Цель-работы-1)
		* 1.2.3. [Процесс](#Процесс-1)
* 2. [Приложения](#Приложения)
	* 2.1. [Ссылка на программу:](#Ссылка-на-программу)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

# Лабораторная работа №7: Знакомство с POSIX потоками

**Выполнил:** Нгуен З.К.  
**Группа:** ИКС-433  
**Дата:** 04.05.25

---

## <a name='На-оценку-3'></a>На оценку 3

### <a name='Тема-Первое-знакомство-с-pthread'></a>Тема: Первое знакомство с pthread

### <a name='Цель-работы'></a>Цель работы:
- Создание потоков
- Ожидание потоков
- Добавление параметров потока
- Завершение потока без ожидания
- Вывод текста о завершении потока
- Создание простого Sleepsort

### <a name='Процесс'></a>Процесс:
1) Создаем поток с помощью pthread_create()
Родительский поток выводит текст после завершения дочернего потока

```c
void* thread_func(void* arg) {
    for(int i=0; i<5; i++) {
        printf("Дочерний поток: строка %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    pthread_join(thread, NULL);
    printf("Родительский поток завершен\n");
    return 0;
}
```

![Вывод потока](../img/image.png)

2) Задаем параметры потока
```c
void* thread_func_params(void* arg) {
    char** lines = (char**)arg;
    for (int i = 0; lines[i] != NULL; i++) {
        printf("%s\n", lines[i]);
        sleep(1); 
    }
    return NULL;
}
```
В main():
```c
char* lines1[] = {"Поток 1: строка 1", "Поток 1: строка 2", NULL};
    char* lines2[] = {"Поток 2: строка A", "Поток 2: строка B", NULL};
    pthread_t threads[4];
    pthread_create(&threads[0], NULL, thread_func_params, lines1);
    pthread_create(&threads[1], NULL, thread_func_params, lines2);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
```

![Вывод потока](../img/image2.png)

3) Дочерний поток перед завершением распечатывает сообщение
```c
void cleanup(void* arg) {
    printf("Поток завершается: %s\n", (char*)arg);
}
void* thread_func_cleanup(void* arg) {
    pthread_cleanup_push(cleanup, "Уборка перед отменой потока");
    while (1) {
        printf("Дочерний поток работает...\n");
        sleep(1);
    }
    pthread_cleanup_pop(0);
    return NULL;
}
```
В main():
```c
 pthread_create(&thread, NULL, thread_func_cleanup, NULL);
    sleep(2); 
    pthread_cancel(thread); 
    pthread_join(thread, NULL);
```

![Работа потока перед отменой](../img/image3.png)

4) Создание Sleepsort
```c
void* sleepsort(void* arg) {
    int val = *(int*)arg;
    sleep(val);
    printf("%d ", val);
    return NULL;
}
```
В main():
```c
int arr[] = {3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    pthread_t sleep_threads[n];
    printf("\nSleepsort: ");
    for (int i = 0; i < n; i++) {
        pthread_create(&sleep_threads[i], NULL, sleepsort, &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(sleep_threads[i], NULL);
    }
    printf("\n");

    return 0;
```

![Результат сортировки](../img/image3.png)

---

<a name='На-оценку-4'></a>На оценку 4
<a name='Тема-Перемножение-матриц'></a>Тема: Перемножение матриц
<a name='Цель-работы-1'></a>Цель работы:
- Перемножение квадратных матриц NxN
- Замеры времени выполнения (с момента создания потоков и до завершения работы потоков)
- Построение графика в python

<a name='Процесс-1'></a>Процесс:

1) Перемножение матриц в функции multiply
```c
void* multiply(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }
    return NULL;
}
```
2) Замер времени выполнения программы
```c
gettimeofday(&start, NULL);

for (i = 0; i < threads; i++) pthread_create(...);
for (i = 0; i < threads; i++) pthread_join(...);

gettimeofday(&end, NULL);
```
3) Просмотр выполнения алгоритма через gdb

![Запуск в gdb](../img/image4.png)

<a name='Приложения'></a>Приложения

4) Вывод графика Зависимости времени выполнения от размера матрицы и количества потоков на Python.
![График на python](../img/image5.png)
Обьяснение:
1) Программа работает параллельно. При умножении матриц каждая строка результирующей матрицы вычисляется независимо
2) Происходит распределение работы между потоками:
Чем чем больше потоков, тем быстрее работает программа.
Пример: при N =100 и 16 потоков, каждый поток обрабатывает 6-7 строк за одну секунду
Дальнейшее увеличение даёт минимальный прирост к скорости обработки.

<a name='Ссылка-на-программу'></a>Ссылка на программу:

[График](https://github.com/Darkness1853/programming-Python/blob/669e6bce4231aee4a7645d86178b3f7f946059dd/other/project/graph)

---

Справочник:
Pthread:
1) pthread_create() - создание нового потока.
2) pthread_join() - ожидание завершения указанного потока / Объедининение двух нитей в одну.
3) pthread_cancel() - отправление запроса на отмену указанного потока.
4) pthread_cleanup_push() - добавляет функции очистки, которая будет вызвана при отмене или завершении потока.
5) pthread_cleanup_pop() - удаляет установленный обработчик очистки (0) или удаляет и выполняет его (не 0)
Mutex:
1) PTHREAD_MUTEX_INITIALIZER - статическая инициализация мьютекса с параметрами по умолчанию.
2) PTHREAD_COND_INITIALIZER – статическая инициализация условной переменной.
3) pthread_mutex_lock() – блокирует мьютекс. Если мьютекс уже заблокирован другим потоком, текущий поток ждет его освобождения.
4) pthread_mutex_unlock() – разблокирует мьютекс, позволяя другим потокам захватить его.
5) pthread_cond_wait()- разблокирует мьютекс (mutex), переводит текущий поток в режим ожидания, пока не придет сигнал (pthread_cond_broadcast или pthread_cond_signal). После получения сигнала снова блокирует мьютекс и продолжает выполнение.
6) pthread_cond_broadcast() – пробуждает все потоки, ожидающие на переменной ()
7) pthread_cond_signal() - пробуждает только один поток.

---


