#include "util.h"
#include <pthread.h>
#include <stdio.h>

void	action(pthread_mutex_t *mutex, char *str, int id)
{
	pthread_mutex_lock(mutex);
	printf(str, get_current_time(), id);
	pthread_mutex_unlock(mutex);
}

void	func(pthread_mutex_t *mutex)
{
	action(mutex, "%ld %d is eating\n", 1);
	usleep(1000);
	action(mutex, "%ld %d is sleeping\n", 1);
	usleep(1000);
	action(mutex, "%ld %d is thinking\n", 1);
}

int main ()
{
	int len = 20;
	int	i = -1;
	pthread_t thread[len];
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	while (++i < len)
	{
		pthread_create(&thread[i], NULL, (void *)func, (void*)&mutex);
		pthread_detach(thread[i]);
	}
	while(1)
		sleep(10);
}
