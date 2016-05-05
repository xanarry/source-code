#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int i = 0;
sem_t sem_work;//控制工作线程的信号量
sem_t sem_input;//控制输入线程的信号量

int sum(int n)//求和函数
{
    return (1 + n) * n / 2;
}

void * work_func(void * n)//工作函数, 求和
{
    printf("work start...\n");
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    printf("enter loop\n");
    while (1)
    {
        sem_wait(&sem_work);//等到有工作请求才向后执行, 否则阻塞在此处
        printf("you input: %d, sum(0-%d)=%d\n", i, i, sum(i));//执行工作
        sem_post(&sem_input);//启动输入函数的信号量
    }
    printf("finish loop\n");
    pthread_exit(NULL);
}

void * input_func(void * n)
{
    printf("input start...\n");
    while (1)
    {
        scanf("%d", &i);//输入一个输入
        sem_post(&sem_work);//启动功能函数执行计算
        sem_wait(&sem_input);//等待功能函数执行完后唤醒再次输入以实现严格的轮换
        if (i == -1)//如果输入了一个负数, 那么关闭功能函数, 并退出自身循环, 退出执行
        {
            int res = pthread_cancel(*(pthread_t *) n);
            if (res == 0)
                printf("work thread has canceled\n");
            break;
        }
    }
    printf("input end...\n");
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t work;
    pthread_t input;

    sem_init(&sem_work, 0, 0);
    sem_init(&sem_input, 0, 0);

    pthread_create(&work, NULL, work_func, NULL);
    pthread_create(&input, NULL, input_func, &work);

    pthread_join(work, NULL);
    pthread_join(input, NULL);
    printf("thread stop at:%d\n", i);
    return 0;
}
