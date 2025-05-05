#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// Создание потока
void* thread_func(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Дочерний поток: строка %d\n", i);
        sleep(1); 
    }
    return NULL;
}

// Параметры потока
void* thread_func_params(void* arg) {
    char** lines = (char**)arg;
    for (int i = 0; lines[i] != NULL; i++) {
        printf("%s\n", lines[i]);
        sleep(1); 
    }
    return NULL;
}

// Очистка перед завершением
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

// Sleepsort
void* sleepsort(void* arg) {
    int val = *(int*)arg;
    sleep(val);
    printf("%d ", val);
    return NULL;
}

int main() {
    // Создание и ожидание одного потока
    pthread_t thread;
    printf("Родительский поток запускает дочерний...\n");
    pthread_create(&thread, NULL, thread_func, NULL);
    pthread_join(thread, NULL);
    printf("Родительский поток: дочерний завершился\n");

    // 4 потока с разными параметрами
    char* lines1[] = {"Поток 1: строка 1", "Поток 1: строка 2", NULL};
    char* lines2[] = {"Поток 2: строка A", "Поток 2: строка B", NULL};
    pthread_t threads[4];
    pthread_create(&threads[0], NULL, thread_func_params, lines1);
    pthread_create(&threads[1], NULL, thread_func_params, lines2);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    //  Отмена потоков
    pthread_create(&thread, NULL, thread_func_cleanup, NULL);
    sleep(2);
    pthread_cancel(thread);
    pthread_join(thread, NULL);

    // Sleepsort
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
}
//gcc -lpthread task1.c -o task1 && ./task1