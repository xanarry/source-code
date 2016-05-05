#include <stdio.h>
#include <pthread.h>

void * func(void * n)
{
    printf("this is thread: %ld\n", (long) n);
    int sum = 0;
    for (int i = 0; i < 100000000; i++)
        sum =+ i;
    pthread_exit((void *) n);
}

int main(int argc, char const *argv[])
{
    const int n = 4;
    pthread_t threads[n];
    long i;
    for (i = 0; i < n; i++)
    {
        printf("Main: creating thread %ld\n", i);
        if (pthread_create(threads + i, NULL, func, (void *) i) != 0)
        {
            printf("create thread %ld failed\n", i);
            return 0;
        }
    }

    void *status;
    for (i = 0; i < n; i++)
    {
        pthread_join(threads[i], &status);
        printf("Main thread wait for thread: %ld OK\n", (long) status);
    }
    printf("Main thread has finish\n");
    return 0;
}