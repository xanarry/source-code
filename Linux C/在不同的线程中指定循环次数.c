/*
子线程循环 5 次，
接着主线程循环 10 次，
接着又回到子线程循环 5 次，
接着再回到主线程又循环 10 次，如此循环10次.
写出代码
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_child, set_main;

void *func()
{
    while (1)
    {
        sem_wait(&sem_child);
        for (int i = 1; i <= 5; i++)
            printf("\t\tchild_thread: %d\n", i);
        sem_post(&set_main);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t thread;
    sem_init(&sem_child, 0, 1);
    sem_init(&set_main, 0, 0);
    pthread_create(&thread, NULL, func, NULL);

    for (int i = 1; i <= 5; i++)
    {
        sem_wait(&set_main);
        for (int j = 1; j <= 10; j++)
            printf("main_thread: %d\n", j);
        sem_post(&sem_child);
    }
    return 0;
}