#include <stdio.h>
#include "util.h"
#include "type.h"

static int	check_arg(char	*arg)
{
	int	len;
	int	sign_cnt;

	len = ft_strlen(arg);
	while (--len >= 0)
	{
		if (!ft_isdigit(arg[len]))
			return (1);
		else
			break ;
	}
	sign_cnt = 0;
	while (--len >= 0)
	{
		if (sign_cnt > 0)
			return (1);
		if (ft_isdigit(arg[len]))
			continue ;
		if (arg[len] == '-' || arg[len] == '+')
			sign_cnt++;
		else
			return (1);
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (1);
	i = 0;
	while (++i < ac)
		if (check_arg(av[i]))
			return (1);
	return (0);
}

int	check_count(t_rule	*rule)
{
	if (rule->size == 0)
		return (0);
	if (rule->max_eat_flag && rule->max_eat_count <= 0)
		return (0);
	return (1);
}

void	check_philos_die(t_philosopher *philos, t_rule *rule)
{
	int		i;
	long	cur_time;
	long	philo_eat_time;
	long	eat_count;

	i = -1;
	while (1)
	{
		if (++i == rule->size)
			i = 0;
		pthread_mutex_lock(philos[i].m_eat);
		philo_eat_time = philos[i].eat_time;
		eat_count = rule->eat_count;
		pthread_mutex_unlock(philos[i].m_eat);
		cur_time = get_passed_time(rule->s_time);
		if (cur_time - philo_eat_time >= rule->life_time \
			|| (rule->max_eat_flag && eat_count <= 0))
		{
			rule->status = DIE;
			pthread_mutex_lock(&rule->m_print);
			if (cur_time - philo_eat_time >= rule->life_time)
				printf("%ld %d died\n", cur_time, philos->id);
			return ;
		}
	}
}
