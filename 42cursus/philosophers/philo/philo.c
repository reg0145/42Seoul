#include "philo.h"

void	philos_eat_count(t_philosopher *philos)
{
	if (philos->rule->max_eat_flag)
	{
		if (philos->eat_count > 0)
			philos->eat_count--;
		else if (philos->eat_count == 0)
		{
			philos->eat_count--;
			philos->rule->eat_count--;
		}
	}
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
		free(rule);
	}
	if (philos != NULL)
		free(philos);
}

void	philos_life(t_philosopher *philos)
{
	t_rule	*rule;
	long	time;

	rule = philos->rule;
	if (philos->id % 2 == 0)
		uxsleep((double)rule->eat_time / 2);
	while (1)
	{
		pthread_mutex_lock(philos->right_fork);
		uxprintf(philos, "%ld %d has taken a fork\n");
		pthread_mutex_lock(philos->left_fork);
		uxprintf(philos, "%ld %d has taken a fork\n");
		time = get_passed_time(rule->s_time);
		pthread_mutex_lock(philos->m_eat);
		philos->eat_time = time;
		philos_eat_count(philos);
		pthread_mutex_unlock(philos->m_eat);
		uxprintf(philos, "%ld %d is eating\n");
		uxsleep(rule->eat_time);
		pthread_mutex_unlock(philos->right_fork);
		pthread_mutex_unlock(philos->left_fork);
		uxprintf(philos, "%ld %d is sleeping\n");
		uxsleep(rule->sleep_time);
		uxprintf(philos, "%ld %d is thinking\n");
	}
}

void	begin_philos_life(t_philosopher *philos, int len)
{
	int			i;
	pthread_t	pthread;

	i = -1;
	while (++i < len)
	{
		if (i == len - 1 && i % 2 == 0)
			usleep(philos->rule->eat_time / 2);
		if (pthread_create(&pthread, 0, (void *)philos_life \
			, (void *)&philos[i]))
			return ;
		if (pthread_detach(pthread))
			return ;
	}
}

int	main(int ac, char **av)
{
	t_philosopher	*philos;
	t_rule			*rule;

	if (check_args(ac, av) || init(&philos, &rule, ac, av))
	{
		printf("Error");
		return (0);
	}
	if (check_count(rule))
	{
		begin_philos_life(philos, philos->rule->size);
		check_philos_die(philos, rule);
	}
	uxfree(philos, rule);
	while(1);
	return (0);
}
