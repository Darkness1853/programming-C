#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 2500

int N, threads;
int A[MAX_N][MAX_N], B[MAX_N][MAX_N], C[MAX_N][MAX_N];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int current_turn = 0; 
typedef struct {
    int start_row;
    int end_row;
    int thread_id;
} ThreadData;

void* multiply(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    
    // Ожидание очереди
    pthread_mutex_lock(&mutex);
    while (current_turn != data->thread_id) {
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);

    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    pthread_mutex_lock(&mutex);
    current_turn = (current_turn + 1) % threads;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void multiply_remaining(int start_row, int end_row) {
    // Ожидание своей очереди 
    pthread_mutex_lock(&mutex);
    while (current_turn != threads) {
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    pthread_mutex_lock(&mutex);
    current_turn = (current_turn + 1) % (threads + 1);
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Использование: %s <размер матрицы> <число потоков>\n", argv[0]);
        return 1;
    }
    
    N = atoi(argv[1]);
    threads = atoi(argv[2]);

    // Проверка и корректировка количества потоков
    if (threads > N) threads = N;
    if (threads < 1) threads = 1;

    // Заполнение матриц единицами
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }

    // Подготовка данных для потоков
    pthread_t thread_ids[threads];
    ThreadData thread_data[threads];
    int rows_per_thread = N / threads;
    int remaining_rows = N % threads;
    int current_row = 0;

    clock_t start = clock();

    // Создание и запуск потоков
    for (int i = 0; i < threads; i++) {
        thread_data[i].start_row = current_row;
        thread_data[i].end_row = current_row + rows_per_thread;
        if (i < remaining_rows) thread_data[i].end_row += 1;
        thread_data[i].thread_id = i;
        
        pthread_create(&thread_ids[i], NULL, multiply, &thread_data[i]);
        current_row = thread_data[i].end_row;
    }

    // Обработка оставшихся строк в основном потоке
    if (remaining_rows > 0) {
        int start_row = threads * rows_per_thread;
        multiply_remaining(start_row, N);
    }

    // Ожидание завершения потоков
    for (int i = 0; i < threads; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время выполнения: %f сек.\n", time_spent);

    // Вывод матриц (если N <= 5)
    if (N <= 5) {
        printf("Матрица A:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) printf("%d ", A[i][j]);
            printf("\n");
        }
        printf("Матрица B:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) printf("%d ", B[i][j]);
            printf("\n");
        }
        printf("Результат C:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) printf("%d ", C[i][j]);
            printf("\n");
        }
    }

    return 0;
}
//gcc -lpthread task2.c -o task2 && ./task2 8 4