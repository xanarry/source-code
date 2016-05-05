#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int sum = 0;
pthread_mutex_t mutex;

void * func(void * n)
{
    printf("thread %ld start\n", pthread_self());
    int *mark = (int *) n;
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        if (*mark == 1)
            sum++;
        else
            sum--;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t thread1, thread2;
    int plus = 1;
    int minus = 0;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, func, (void *) &plus);
    pthread_create(&thread2, NULL, func, (void *) &minus);

    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        sum++;
        pthread_mutex_unlock(&mutex);
    }
        
        
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("sum: %d\n", sum);
    return 0;
}