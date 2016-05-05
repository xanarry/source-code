#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define N 3

/*
编写一个程序，开启3个线程，
这3个线程的ID分别为A、B、C，
每个线程将自己的ID在屏幕上打印10遍，
要求输出结果必须按ABC的顺序显示；如：ABCABC….依次递推
*/

pthread_t threads[N];
sem_t sems[N];

void * func(void * id)
{
    int mark = *(long *) id;
    for (int i = 0; i < 10; i++)
    {
        //此处三个线程公用一个函数, 所以, 在输出id的时候需要使用pthread_equal()判断当前运行的线程具体是哪一个线程
        for (int j = 0; j < N; j++)
        {
            if (pthread_equal(pthread_self(), threads[j]))
            {
                sem_wait(&sems[j % N]);//等待当前进程的唤醒信号
                printf("%c", 'A' + j);//输出进程ID
                sem_post(&sems[(j + 1) % N]);//唤醒下一个进程, 0-1-2-0-1-2形成一个环
            }
        }
    }
}

int main(int argc, char const* argv[])
{
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            sem_init(&sems[i], 0, 1);
        else
            sem_init(&sems[i], 0, 0);
    }

    for (long i = 0; i < N; i++)
        pthread_create(threads + i, NULL, func, (void *) &i);

    for (int i = 0; i < N; i++)
        pthread_join(threads[i], NULL);
    return 0;
}

