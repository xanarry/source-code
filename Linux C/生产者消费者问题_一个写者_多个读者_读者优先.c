#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

pthread_mutex_t cnt_mutex;
sem_t sem_write;

int reader_count = 0;
int content = 1;
pthread_t readers[10];

void * writer_func()
{
    printf("writer start\n");
    while (1)
    {
        sem_wait(&sem_write);//wait fro reader release mutex

        content++;//start writing, change the value
        printf("writer: %d\n", content);

        sem_post(&sem_write);//release mutex for reader
    }
    pthread_exit(NULL);
}

/*
为什么会读者优先, 从读者和写者的代码可以看出, 写者的代码中仅仅是等待信号, 然后执行写的功能
在读者的代码中, 读者总是给写者发出信号, 在读过的过程中, 有任何线程在读文件, 就不能通知写者工作
只用在所有读者都没有在读文件时读者才通知写者可以写文件, 所以是读者优先 
*/
void * reader_func(void * n)
{
    printf("reader start\n");
    while (1)
    {
        pthread_mutex_lock(&cnt_mutex);//to prevent that mutiply thread access reader_count simultaneously
        if (reader_count == 0)//if has no reader read file, thus, writer must writing it
            sem_wait(&sem_write);//waiting for writer finish write
        reader_count++;//reader's count plus 1
        pthread_mutex_unlock(&cnt_mutex);//release count mutex

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


