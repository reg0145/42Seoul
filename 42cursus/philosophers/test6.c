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
	if (-1)
		printf("ok");

}
