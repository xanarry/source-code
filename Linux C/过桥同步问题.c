/*
一座小桥（最多只能承重两个人）横跨南北两岸，
任意时刻同一方向只允许一人过桥，
南侧桥段和北侧桥段较窄只能通过一人，
桥的中央一处宽敞，允许两个人通过或者休息。
使用信号灯和PV操作写出南，北两岸过桥的同步算法。

sem_north 1
sem_south 1
load 2

假定桥上有两个信号灯, 两端桥头各有一个开关, 一个人上桥的时候按一下开关, 打开灯, 下桥的时候按一下开关, 关闭灯
如果其中有关闭的灯, 说明现在可以通行
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

sem_t sem_north;
sem_t sem_south;
sem_t sem_load;

void * south_func()//south forward
{
    printf("start south_func\n");
    while (1)
    {
        sem_wait(&sem_load);//桥上能容2人,

        //因为从桥的两端同时各可以进入一个人, 所以分别检查南北桥头能否进入
        sem_wait(&sem_south);
        printf("S_enter bridge forward to south\n");
        sem_post(&sem_south);

        sem_wait(&sem_north);
        printf("S_enter bridge forward to north\n");
        sem_post(&sem_north);

        sem_post(&sem_load);
    }
}

void * north_func()//north forward
{
    printf("start north_func\n");
    while (1)
    {
        sem_wait(&sem_load);

        sem_wait(&sem_north);
        printf("N_enter bridge forward to north\n");
        sem_post(&sem_north);

        sem_wait(&sem_south);
        printf("N_enter bridge forward to south\n");
        sem_post(&sem_south);

        sem_post(&sem_load);
    }
}


int main()
{
    pthread_t south;
    pthread_t north;

    sem_init(&sem_north, 0, 1);//先南最多1人
    sem_init(&sem_south, 0, 1);//向北最多1人
    sem_init(&sem_load, 0, 1);//桥的容量为2人

    pthread_create(&south, NULL, south_func, NULL);
    pthread_create(&north, NULL, north_func, NULL);

    pthread_join(south, NULL);
    pthread_join(north, NULL);
    return 0;
}

