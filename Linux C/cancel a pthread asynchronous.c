#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
//asynchronous in chines means YIBU
void * func(void * n)
{
    /*
    this function is a dead loop, but we use asynchronous here, that means, anyway,
    thread will immediately be canceled while get pthread_cancel command
    */
    printf("thread start...\n");
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    int i = 0;
    while (1)
    {
        i++;
    }
    printf("thread end...\n");
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t thread;
    pthread_create(&thread, NULL, func, NULL);
    sleep(1);//to prevent cancel start before new thread, if thread not start, a cancel will be effect immediatly
    int res = pthread_cancel(thread);
    if (res == 0)
        printf("thread has been canceled\n");
    pthread_join(thread, NULL);
    return 0;
}