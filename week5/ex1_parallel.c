#include <stdio.h>
#include <pthread.h>

void print_thread(int n)
{
    printf("salam aleykum from thread number %d\n", n);
}

int main(void)
{
    int N = 10;
    pthread_t threads[N];
    for (int i = 0; i < N; i++)
    {
        printf("new thread %d is created\n", i + 1);
        pthread_create(&threads[i], NULL, &print_thread, i + 1);
    }
    for (int i = 0; i < N; i++)
    {
        pthread_join(threads[i], 0);
        printf("aleykum as-salam from thread number %d\n", i + 1);
    }
}