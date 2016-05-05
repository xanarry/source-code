#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int i = 0;
sem_t sem_work;
sem_t sem_input;

int sum(int n)
{
    return (1 + n) * n / 2;
}

void * work_func(void * n)
{
    printf("work start...\n");
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    printf("enter loop\n");
    while (1)
    {
        sem_wait(&sem_work);
        printf("you input: %d, sum(0-%d)=%d\n", i, i, sum(i));
        sem_post(&sem_input);
    }
    printf("finish loop\n");
    pthread_exit(NULL);
}

void * input_func(void * n)
{
    printf("input start...\n");
    while (1)
    {
        scanf("%d", &i);
        sem_post(&sem_work);
        sem_wait(&sem_input);
        if (i == -1)
        {
            int res = pthread_cancel(*(pthread_t *) n);
            if (res == 0)
                printf("work thread has canceled\n");
            break;
        }
    }
    printf("input end...\n");
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t work;
    pthread_t input;

    sem_init(&sem_work, 0, 0);
    sem_init(&sem_input, 0, 0);

    pthread_create(&work, NULL, work_func, NULL);
    pthread_create(&input, NULL, input_func, &work);

    pthread_join(work, NULL);
    pthread_join(input, NULL);
    printf("thread stop at:%d\n", i);
    return 0;
}

