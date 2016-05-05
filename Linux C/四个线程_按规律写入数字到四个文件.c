/*
有四个线程1,2,3,4
线程1的功能就是输出1,
线程2的功能就是输出2,
以此类推...
现在有四个文件ABCD.初始都为空.现要让四个文件呈如下格式:
A:1 2 3 4 1 2....
B:2 3 4 1 2 3....
C:3 4 1 2 3 4....
D:4 1 2 3 4 1....
请设计程序。

*/

/*
四个文件, 四个线程, 代码的处理方式为从数字1开始对每个文件输出一个数字,输出到了4个文件后,
就跳到第二列开始纵向向每个文件输出第二个字符,
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 4

pthread_mutex_t mutex;
pthread_t threads[N];
sem_t sems[N];

char *file_name[] = {"1.txt", "2.txt", "3.txt", "4.txt"};
FILE *files[N];

int file_id = 0;//标记应该输出的文件编号
int cow = 0;//输出列编号

void * func()
{
    for (int m = 0; m < 20; m++)//在每个文件中输出20个字母
    {
        /*如果在函数中加个参数接收线程的ID, 定义变量i并将ID赋值给i,那么这个查找id的循环可以从代码中删除,不影响工作*/
        for (int i = 0; i < N; i++)//遍历线程, 查找线程ID, 根据不同的线程执行不同的行为
        {
            if (pthread_equal(pthread_self(), threads[i]))//如果找到对应的线程ID
            {
                sem_wait(&sems[i]);//唤醒该线程
                /*代码中为方便查看,直接输出写入到文件的过程,如果输出到文件将下面一行代码注释*/
                //fprintf(files[file_id], "%d", i + 1);
                printf("%s add:%d\n", file_name[file_id], i + 1);
                pthread_mutex_lock(&mutex);//下面的代码存在自加和其他运算符号, 所以要设为临界区
                file_id++;//每对一个文件输出一个数字后, 就跳到下一个文件
                if (file_id == 4)//如果已经对4个文件进行了一次完整的轮询
                {
                    file_id = 0;//那么又从第一个文件开始输出
                    cow++;//并且跳到下一列开始
                    cow = cow % N;//列输入的起点是12341234有规律的, 所以在这里根据这个规律激活不同的线程输出不同数字
                    sem_post(&sems[cow]);//激活按规律得到的线程
                }
                else//如果没有对文件进行一次完整的轮询, 直接对文件调用下一个线程输出下一个数字即可
                    sem_post(&sems[(i + 1) % N]);
                pthread_mutex_unlock(&mutex);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < N; i++)//创建4个文件分别保存每个线程的写入内容
        files[i] = fopen(file_name[i], "w");

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            sem_init(sems + i, 0, 1);//内容从1也就是第一个线程开始执行
        else
            sem_init(sems + i, 0, 0);
    }

    for (int i = 0; i < N; i++)//开启4个线程
        pthread_create(threads + i, NULL, func, NULL);

    for (int i = 0; i < N; i++)//等待4个线程结束
        pthread_join(threads[i], NULL);

	printf("Process eixt\n");
    return 0;
}
