#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#define BUF_SIZE 128

char str[128];
sem_t sem;

void * func(void *n)
{
    sem_wait(&sem);
    while (strncmp("end", str, 3) != 0)
    {
        printf("You input: %s length: %d\n", str, (int) strlen(str) - 1);
        sem_wait(&sem);
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t thread;
    int res;
    res = sem_init(&sem, 0, 0);
    if (res != 0)
    {
        printf("initialize semaphore failed\n");
        return -1;
    }

    res = pthread_create(&thread, NULL, func, NULL);
    if (res != 0)
    {
        printf("create thread failed\n");
        return -1;
    }

    char *str_ary[10] = {"1", "11", "111", "1111", "11111", "111111", "1111111", "11111111", "111111111", "1111111111"};
    printf("Input some text, Enter 'end' to stop\n");
    
    //if use the following comment code there will be only one value output
    /*for (int i = 0; i < 10; i++)
    {
        strcpy(str, str_ary[i]);
        sem_post(&sem);
        //sleep(1);
    }
    strcpy(str, "end");
    sem_post(&sem);*/

    while (strncmp("end", str, 3) != 0)
    {
        fgets(str, BUF_SIZE, stdin);
        sem_post(&sem);
    }

    res = pthread_join(thread, NULL);
    if (res != 0)
    {
        printf("Wait thread failed\n");
        return -1;
    }
    printf("Thread joined\n");
    sem_destroy(&sem);
    return 0;
}   