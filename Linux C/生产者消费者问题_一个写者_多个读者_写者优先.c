#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

pthread_mutex_t cnt_mutex;
sem_t sem_write;
sem_t pre;

int reader_count = 0;
int content = 1;
pthread_t readers[10];

void * writer_func()
{
    printf("writer start\n");
    while (1)
    {
        sem_wait(&pre);
        sem_wait(&sem_write);//wait fro reader release mutex

        content++;//start writing, change the value
        printf("writer: %d\n", content);

        sem_post(&sem_write);//release mutex for reader
        sem_post(&pre);
    }
    pthread_exit(NULL);
}

/*
如果希望写进程优先，即当有读进程正在读共享文件时，有写进程请求访问，这时应禁止后续读进程的请求，
等待到已在共享文件的读进程执行完毕则立即让写进程执行，只有在无写进程执行的情况下才允许读进程再次运行

与读者优先的代码相比, 写者优先的代码仅仅多加了一个信号量和两对pv操作,
解释之前仔细看看读者的代码, 很明显读者的代码分为了3个部门, 

第一个部分, 判断写者是否在工作
第二个部门, 读取文件
第三个部分, 读取文件完成, 释放一个读者, 如果现在读者的数量为0, 那么就通知写者工作

我们可以把上面三个部分简单归结为: 进, 工作, 出.

那么如果实现写者优先?
因为只有没有读者在读取文件时写者才能工作, 因此, 一旦写者发出请求后, 我们限制(或者说关闭)进入的门, 而不关闭出去的门
那么很快, 在读者读者数量就会变成0, 从而写者进入临界区进行写工作, 写完成后才通知读者打开进入的门

所以, 再开一个信号量pre, 管理这个门
写者在写前先请求打开门, 如果能打开, 就执行写操作
读者在读之前先请求打开们, 如果能打开, 就执行读操作, 写者在每访一个读者进来后, 就会把门为写者打开
在读者出的代码中, 读者在释放文件的锁, 那么写者就能完全进行写操作了
*/
void * reader_func(void * n)
{
    printf("reader start\n");
    while (1)
    {
        sem_wait(&pre);
        pthread_mutex_lock(&cnt_mutex);//to prevent that mutiply thread access reader_count simultaneously
        if (reader_count == 0)//if has no reader read file, thus, writer must writing it
            sem_wait(&sem_write);//waiting for writer finish write
        reader_count++;//reader's count plus 1
        pthread_mutex_unlock(&cnt_mutex);//release count mutex
        sem_post(&pre);//open the gate for writer after permit enter a reader

        printf("cur reader count:%d read_v:%d\n", reader_count, content);

        pthread_mutex_lock(&cnt_mutex);//mutual access varable count
        reader_count--;//decrease reader's count for 1
        if (reader_count == 0)//if has no reader are reading file
            sem_post(&sem_write);//active writer to write
        pthread_mutex_unlock(&cnt_mutex);//release mutex for reader_count
    }
    pthread_exit(NULL);
}

int main(int argc, char const* argv[])
{
    pthread_t writer;
    pthread_t reader;

    sem_init(&sem_write, 0, 1);
    sem_init(&pre, 0, 1);

    pthread_create(&writer, NULL, writer_func, NULL);
    pthread_create(&reader, NULL, reader_func, NULL);

    /*can create more than one reader thread here, but only on writer thread is available*/

    //for (int i = 0; i < 10; i++)
    //    pthread_create(readers + i, NULL, reader_func, (void *) i);

    pthread_join(writer, NULL);
    pthread_join(reader, NULL);

    //for (int i = 0; i < READER_COUNT; i++)
    //    pthread_join(readers[i], NULL);

    printf("process exit\n");
    return 0;
}



