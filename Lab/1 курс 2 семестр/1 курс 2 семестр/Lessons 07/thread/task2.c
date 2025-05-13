#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>  

#define MAX_N 2500

int N, threads;
int A[MAX_N][MAX_N], B[MAX_N][MAX_N], C[MAX_N][MAX_N];

typedef struct {
    int start_row;
    int end_row;
} ThreadData;

void* multiply(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Используйте так: %s <размер матрицы> <количество потоков>\n", argv[0]);
        return 1;
    }
    
    N = atoi(argv[1]);
    threads = atoi(argv[2]);

    if (threads > N) threads = N;
    if (threads < 1) threads = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
            C[i][j] = 0;
        }
    }

    pthread_t thread_ids[threads];
    ThreadData thread_data[threads];
    int rows_per_thread = N / threads;
    int remaining_rows = N % threads;
    int current_row = 0;

    struct timeval start, end; 
    
    // Инициализация атрибутов потоков
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    gettimeofday(&start, NULL); 

    // Создание и запуск потоков
    for (int i = 0; i < threads; i++) {
        thread_data[i].start_row = current_row;
        thread_data[i].end_row = current_row + rows_per_thread;
        if (i < remaining_rows) thread_data[i].end_row += 1;
        
        pthread_create(&thread_ids[i], &attr, multiply, &thread_data[i]);
        current_row = thread_data[i].end_row;
    }

    // Ожидание завершения потоков
    for (int i = 0; i < threads; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    gettimeofday(&end, NULL);  
    
    double time_spent = (end.tv_sec - start.tv_sec) + 
                       (end.tv_usec - start.tv_usec) / 1000000.0;
    
    printf("Время выполнения: %.6f сек.\n", time_spent);  
    // Вывод матриц для небольших размеров
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

    pthread_attr_destroy(&attr);
    return 0;
}
//gcc -lpthread task2.c -o task2 && ./task2 2000 16