/*
在公共汽车上，为了保证乘客的安全，司机和售票员应该协调工作：
停车后才能开门，
关车门后才能行车。
用PV操作来实现他们之间的协调。

1.开门等待停车
2.开车等待关门
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t stop_bus;
sem_t close_door;

void * driver_func()
{
	while (1)
	{
		sem_wait(&close_door);//开车等待关门
		printf("close door and bus start\n");
		sem_post(&stop_bus);
	}
}

void * seller_func()
{
	while (1)
	{
		sem_post(&close_door);//最初车没走, 门没开, 所有先开门
		printf("bus stoped and door open\n");
		sem_wait(&stop_bus);//下一次循环的开始, 等待停车才能开门
	}
}

int main()
{
	pthread_t driver;
	pthread_t seller;

	sem_init(&stop_bus, 0, 0);
	sem_init(&close_door, 0, 0);

	pthread_create(&driver, NULL, driver_func, NULL);
	pthread_create(&seller, NULL, seller_func, NULL);

	pthread_join(driver, NULL);
	pthread_join(seller, NULL);
	return 0;
}
