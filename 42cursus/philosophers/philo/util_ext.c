#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "type.h"

long	get_passed_time(struct timeval s)
{
	struct timeval	e;
	long			time;

	gettimeofday(&e, 0);
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

int	uxprintf(t_philosopher *philos, char *say)
{
	pthread_mutex_lock(&(philos->rule->m_print));
	pthread_mutex_lock(&(philos->rule->m_die));
	if (philos->rule->status == DIE)
		return (1);
	pthread_mutex_unlock(&(philos->rule->m_die));
	printf(say, get_passed_time(philos->rule->s_time), philos->id);
	pthread_mutex_unlock(&(philos->rule->m_print));
	return (0);
}

void	uxfree(t_philosopher *philos, t_rule *rule)
{
	int	i;

	if (rule != NULL)
	{
		if (rule->forks != NULL)
		{
			i = -1;
			while (++i < rule->size)
				pthread_mutex_destroy(&rule->forks[i]);
			free(rule->forks);
		}
		if (rule->m_eat != NULL)
		{
			i = -1;
			while (++i < rule->size)
				pthread_mutex_destroy(&rule->m_eat[i]);
			free(rule->m_eat);
		}
		pthread_mutex_destroy(&rule->m_die);
		pthread_mutex_destroy(&rule->m_eat_cnt);
		free(rule);
	}
	if (philos != NULL)
		free(philos);
}

void	set_rule_status(pthread_mutex_t *mutex, int *status, int value)
{
	pthread_mutex_lock(mutex);
	*status = value;
	pthread_mutex_unlock(mutex);
}
