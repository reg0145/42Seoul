#include "util.h"
#include <stdio.h>
#include "util.h"
#include "unistd.h"
#include <sys/time.h>
#include <pthread.h>


void test()
{
	int	cnt;

	cnt = 0;
	while (1)
	{
		printf("%d %d\n", sleep(1), ++cnt);
	}
}

void	freeze_thread()
{

}

void	free_all()
{

}

int	main()
{
	struct timeval s_tv;
	struct timeval e_tv;
	int				cnt;
	pthread_t 		thread;
	/*
	pthread_create(&thread, NULL, (void *)test, NULL);
	cnt = 0;
	while (1)
	{
		printf("%d %d\n", uxsleep(1000), ++cnt);
	}
	*/
	int	*error;

	error = (int *)ft_calloc(1, sizeof(int));
	*error = 1;
	while (*error)
		usleep(10);
	system("leaks main_error");
	freeze_thread();
	free_all();

}
