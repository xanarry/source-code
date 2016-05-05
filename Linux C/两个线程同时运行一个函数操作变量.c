#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int count = 0;

void * func(void *tid)
{
	int a = 0;
	for (int i = 0; i < 10000; i++)
	{
		count++;//count as global varable, so, its final result is between 50 and 100;
		a++;//a as a local varable, so, anyway, a will be 10000
	}
	printf("finish: id=%c  a=%d, count=%d\n", (char *)tid, a, count);
}
/*
为什么count的值是10000到20000
先看看count++的工程, 系统会先创建一个count副本, 然后对副本加1, 再赋值到count上.
再看看线程的执行过程,
假如现在count的值是1,
线程1首先执行count++.
线程1首先创建了一个count的副本值也为1
突然线程1的cpu被线程2夺走, 线程2开始创建一个count的副本, 然后加1并赋值到count上, 实现将count值加1变成2
这个过程完成后, 线程1又夺回的cpu, 接着上次断开的地方允许, 即对副本的值加1再赋值给count, 但当前的副本值为1,
所有再次把2复制给了count, 于是, 两个线程分别执行了一次count++, count值理应为2, 但因为其竞争的过程, 导致
count的值为2
*/
int main(int argc, char const* argv[])
{
	pthread_t thread_a, thread_b;
	char a = 'A';
	char b = 'B';
	pthread_create(&thread_a, NULL, func, (void *) a);
	pthread_create(&thread_b, NULL, func, (void *) b);
	pthread_join(thread_a, NULL);
	pthread_join(thread_b, NULL);
	printf("count=%d\n", count);
	return 0;
}
