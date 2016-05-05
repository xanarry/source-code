#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int flag = 1;
void * func(void * n)
{
    for (int i = 0; i < 10;)
    {
        if (flag == 0)
        {
            printf("0\n");
            flag = 1;
            i++;
        }
        else
            sleep(1);
    }   
}

int main(int argc, char const *argv[])
{
    pthread_t thread;
    int res = pthread_create(&thread, NULL, func, NULL);
    if (res)
    {
        printf("create process failed\n");
        return 0;
    }

    for (int i = 0; i < 10;)
    {
        if (flag == 1)
        {
            printf("1\n");
            flag = 0;
            i++;
        }
        else
            sleep(1);
    }
    pthread_join(thread, NULL);
    printf("over\n");
    return 0;
}