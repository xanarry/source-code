/*
一张圆桌上坐着5名哲学家，每两个哲学家之间的桌上摆一根筷子，桌子的中间是一碗米饭，
哲学家们倾注毕生精力用于思考和进餐，
哲学家在思考时，并不影响他人。
只有当哲学家饥饿的时候，才试图拿起左、 右两根筷子（一根一根地拿起）。
如果筷子已在他人手上，则需等待。
饥饿的哲学家只有同时拿到了两根筷子才可以开始进餐，
当进餐完毕后，放下筷子继续思考。
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#define N 5

sem_t sem_chopsticks[N];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * phi_func(void * n)
{
	int id = (long) n;
	/*eat, convention that each philosopher take left chopstick first, then right chopstick
	  philosopher can eat only if he take two chopstics at the same time*/
	while (1)
	{
		pthread_mutex_lock(&mutex);
		sem_wait(&sem_chopsticks[id]);
		sem_wait(&sem_chopsticks[(id + 1) % N]);
		pthread_mutex_unlock(&mutex);

		printf("philosopher %d eating\n", id);

		sem_post(&sem_chopsticks[id]);
		sem_post(&sem_chopsticks[(id + 1) % N]);

		printf("philosopher %d thinking\n\n", id);
	}
}


int main(int argc, char const* argv[])
{
	pthread_t philosophers[N];
	for (int i = 0; i < N; i++)
		sem_init(&sem_chopsticks[i], 0, 1);

	for (int i = 0; i < N; i++)
		pthread_create(&philosophers[i], NULL, phi_func, (void *) (long) i);

	for (int i = 0; i < N; i++)
		pthread_join(philosophers[i], NULL);
}
