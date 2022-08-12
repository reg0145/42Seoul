#include "philosophers.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // usleep()
#include <pthread.h>
#include <sys/time.h>

t_rule	*init_rule(t_rule *rule, int *args, int len)
{
	int	i;

	rule = (t_rule *)ft_calloc(1, sizeof(t_rule));
	if (!rule)
		return (NULL);
	if (gettimeofday(&rule->s_time, NULL))
		return (NULL);
	rule->life_time = args[1];
	rule->eat_time = args[2];
	rule->sleep_time = args[3];
}

int	init_philos(t_philosopher **philos, int *args, int len)
{
	int	i;

	i = -1;
	while (++i < args[0])
	{
		*philos = (t_philosopher *)ft_calloc(args[0], sizeof(t_philosopher));
		if (!*philos)
			return (1);
	}
}

int	init(t_philosopher **philos, int ac, char **av)
{
	int		i;
	t_rule	*rule;
	int		args[5];

	i = 0;
	while (++i < ac)
	{
		args[i - 1] = ft_atoi(av[i]);
		if (args[i] < 0)
			return (1);
	}
	// id 셋팅
	// 포크 셋팅
	rule->forks = (pthread_mutex_t *)ft_calloc(args[0],sizeof(pthread_mutex_t));
		if (!rule->forks)
			return (1);
	i = -1;
	while (++i < ac)
	{
		if (pthread_mutex_init(&rule->forks[i], NULL))
			return (1);
	}
	if (args[0] > 0)
	{
		i = 0;
		while (++i < args[0])
		{
			(*philos)[i].right_fork = &rule->forks[i];
			(*philos)[i].left_fork = &rule->forks[i - 1];
		}
		(*philos)[0].right_fork = &rule->forks[0];
		(*philos)[0].left_fork = &rule->forks[i - 1];
	}


	return (0);
}

int main (int ac, char **av)
{
	t_philosopher *philos;

	if (check_args(ac, av))
	{
		printf("Error");
		return (0);
	}
	if (init(&philos, ac, av))
	{
		printf("Error");
		return (0);
	}



	printf("start");
	int i = -1;
	while (++i < len)
	{
		if (i == len -1 && i % 2 == 0)
		{
			printf("%d %d is thinking\n", (int)(get_passed_time(rule->s_time) * 1000), len);
			usleep(rule->time.eat / 2);
		}
		pthread_create(&p_thread[i], NULL, (void *)life_cycle, (void*)&philos[i]);
	}
	while (++i < len)
		pthread_detach(p_thread[i]);
	usleep(rule->time.eat / 2);
	sleep(5);
	rule->flag ^= LIVE;
}
