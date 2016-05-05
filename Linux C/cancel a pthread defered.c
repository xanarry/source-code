#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * func(void * n)
{
    /*
    in this function thread is a dead loop, and have no pthread cancel point,
    so, if we add no cancel point, this thread will run forever, to prevent 
    this happen, we shall add a cancel point in the dead loop
    */
    printf("thread start...\n");
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    int i = 0;
    while (1)
    {
        i++;
        pthread_testcancel();//add a cancel point to prevent thread run forever
    }
    printf("thread end...\n");
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t thread;
    pthread_create(&thread, NULL, func, NULL);
    sleep(1);//to prevent cancel start before new thread, if thread not start, a cancel will be effect immediatly
    pthread_cancel(thread);
    pthread_join(thread, NULL);
    return 0;
}