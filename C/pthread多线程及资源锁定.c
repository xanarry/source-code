#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int Buf1_num=0;
int Buf2_num=0;
int Buf1[10];
int Buf2[10];

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void *thread_fun1(void *args);
void *thread_fun2(void *args);
void *thread_fun3(void *args);

int main(void)
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	if (pthread_create(&thread1,NULL,thread_fun1,NULL))
	{
		fprintf(stderr,"Create pthread_fun1 error!\n");
		exit(-1);
	}
	
	if (pthread_create(&thread2,NULL,thread_fun2,NULL))
	{
		fprintf(stderr,"Create pthread_fun2 error!\n");
		exit(-1);
	}
	
	if (pthread_create(&thread3,NULL,thread_fun3,NULL))
	{
		fprintf(stderr,"Create pthread_fun3 error!\n");
		exit(-1);
	}
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	return 0;
}


void * thread_fun1(void *args)
{
	char ch;
	FILE *in1 =fopen("1.dat","r");
	if(in1==NULL)
	{
		printf("Failed to open file!");
		exit (0);
	}

	while (!feof(in1))
	{
		pthread_mutex_lock(&mutex1);
		fscanf(in1, "%d", &Buf1[Buf1_num++]);
		pthread_mutex_unlock(&mutex1);
	}
	fclose(in1);
	return NULL;
}

void *thread_fun2(void *args)
{
	char ch;
	FILE *in2=fopen("2.dat","r");
	if(in2==NULL)
	{
		printf("Failed to open file!");
        exit (0);
	}
	
	while (!feof(in2))
	{
		pthread_mutex_lock(&mutex1);
		fscanf(in2, "%d", &Buf2[Buf2_num++]);
		pthread_mutex_unlock(&mutex1);
	}
	fclose(in2);
	return NULL;
}


void *thread_fun3(void *args)
{
	int i=0;
	while (i < 10)
	{
		pthread_mutex_lock(&mutex1);
		pthread_mutex_lock(&mutex2);
		if(i<Buf1_num && i<Buf2_num)
		{
			fprintf(stderr,"%d+%d=%d,%d*%d=%d\n", Buf1[i], Buf2[i], Buf1[i] + Buf2[i], Buf1[i], Buf2[i], Buf1[i] * Buf2[i]);
			i++;
		}
		pthread_mutex_unlock(&mutex2);
		pthread_mutex_unlock(&mutex1);
	}
	time_t t = time(0);
    char tmp[200];
    strftime(tmp, sizeof(tmp), "%c",localtime(&t) );
    printf("%s\n", tmp);
    return NULL;
}