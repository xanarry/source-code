#include <stdio.h>
#include <string.h>
#include <pthread.h>

char msg[] = "hello world";

void * func(void * str)
{
    printf("start Thread...\nget parameter: %s\n", (char *) str);
    strcpy(msg, "Bye");
    pthread_exit("Thanks for CPU time");
}

int main()
{
    char *arg = "About Thread";
    pthread_t thread;
    int res = pthread_create(&thread, NULL, func, (void *) arg);
    if (res != 0)
    {
        printf("create thread failed");
        return -1;
    }
    else
        printf("create thread successful\n");
    void *status;
    pthread_join(thread, &status);
    printf("%s", (char *) status);

    return 0;
}