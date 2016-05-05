#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
/*
问题描述

桌子上有一只盘子，每次只能向其中放入一个水果。
爸爸专向盘子中放苹果，
妈妈专向盘子中放橘子，
儿子专等吃盘子中的橘子，
女儿专等吃盘子中的苹果。
只有盘子为空时，爸爸或妈妈就可向盘子中放一个水果；
仅当盘子中有自己需要的水果时，儿子或女儿可以从盘子中取出。
*/
sem_t plate_empty;
sem_t apple;
sem_t orange;

void * father_func()
{
	printf("father start\n");
	while (1)//father put apple to plate
	{
		sem_wait(&plate_empty);//wait for plate is empty
		sem_post(&apple);//put a apple
		printf("f+ father put a apple\n");
	}
	pthread_exit(NULL);
}

void * mother_func()
{
	while (1)//mother put orange to plate
	{
		sem_wait(&plate_empty);//wait for plate is empty
		sem_post(&orange);//put a orange
		printf("m+ mother put a orange\n");
	}
	pthread_exit(NULL);
}

void * son_func()
{
	while (1)//son only eat orange
	{
		sem_wait(&orange);//wait an orange in plate an get it
		printf("s- son eat a orange\n");
		sem_post(&plate_empty);//get the orange to set plate empty
	}
	pthread_exit(NULL);
}

void * daughter_func()
{
	while (1)//daughter only eat apple
	{
		sem_wait(&apple);//wait for an apple in the plate
		printf("d- daughter eat a apple\n");
		sem_post(&plate_empty);//get apple to set plate empty
	}
	pthread_exit(NULL);
}

int main(int argc, char const* argv[])
{
	pthread_t father;
	pthread_t mother;
	pthread_t son;
	pthread_t daughter;

	sem_init(&apple, 0, 0);
	sem_init(&orange, 0, 0);
	sem_init(&plate_empty, 0, 1);

	pthread_create(&father, NULL, father_func, NULL);
	pthread_create(&mother, NULL, mother_func, NULL);
	pthread_create(&son, NULL, son_func, NULL);
	pthread_create(&daughter, NULL, daughter_func, NULL);

	pthread_join(father, NULL);
	pthread_join(mother, NULL);
	pthread_join(son, NULL);
	pthread_join(daughter, NULL);
	printf("process finish\n");
	return 0;
}
