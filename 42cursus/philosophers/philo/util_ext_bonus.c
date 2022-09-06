#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "type.h"

long	get_passed_time(struct timeval s)
{
	struct timeval	e;
	long			time;

	if (gettimeofday(&e, 0) == -1)
		return (0);
	time = e.tv_sec - s.tv_sec;
	time = ((time * 1000000) + e.tv_usec) - s.tv_usec;
	return (time / 1000);
}

long	uxsleep(double ms)
{
	double			passed;
	double			now;
	struct timeval	s;
	struct timeval	e;

	if (gettimeofday(&s, 0) == -1)
		return (0);
	passed = (double)ms / 1000;
	now = 0;
	while (now < passed)
	{
		usleep(500);
		gettimeofday(&e, 0);
		now = (e.tv_sec - s.tv_sec) + \
				((double)(e.tv_usec - s.tv_usec) / 1000000);
	}
	return (passed);
}

void	uxprintf(t_philosopher *philos, char *say)
{
	sem_wait(philos->rule->sem_print);
	printf(say, get_passed_time(philos->rule->s_time), philos->id);
	sem_post(philos->rule->sem_print);
}
