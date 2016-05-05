#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * func(void * n)
{
    int * x = (int *) n;
    printf("This is a new thread, get n=%d\n", *x);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    int res;
    pthread_t thread;
    int n = 10;
    printf("create new thread\n");
    res = pthread_create(&thread, NULL, func, (void *) &n);
    if (res != 0)
    {
        printf("create thread failed\n");
        exit(-1);
    }
    /*as each run quickly seperately, in order to get the output
    of another thread, so we add this loop here, to avoid that
    main thread exit frist result in we can't see the output in func*/

    for (int i = 0; i < 0x7fffff; i++);
    printf("this is in main thread\n");
    return 0;
}