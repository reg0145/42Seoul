/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:25:10 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 14:51:12 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	check_philo_eat(t_rule *rule)
{
	long	eat_count;

	pthread_mutex_lock(&rule->m_eat_cnt);
	eat_count = rule->eat_count;
	pthread_mutex_unlock(&rule->m_eat_cnt);
	if (rule->max_eat_flag && eat_count <= 0)
	{
		pthread_mutex_lock(&rule->m_print);
		set_rule_status(&rule->m_die, &rule->status, DIE);
		return (1);
	}
	return (0);
}

static int	check_philo_time(t_philosopher *philo, t_rule *rule)
{
	long	cur_time;
	long	philo_eat_time;

	pthread_mutex_lock(philo->m_eat);
	philo_eat_time = philo->eat_time;
	pthread_mutex_unlock(philo->m_eat);
	cur_time = get_passed_time(rule->s_time);
	if (cur_time - philo_eat_time >= rule->life_time)
	{
		pthread_mutex_lock(&rule->m_print);
		set_rule_status(&rule->m_die, &rule->status, DIE);
		if (cur_time - philo_eat_time >= rule->life_time)
			printf("%ld %d died\n", cur_time, philo->id);
		return (1);
	}
	return (0);
}

void	check_philos_die(t_philosopher *philos, t_rule *rule)
{
	int		i;

	i = -1;
	while (1)
	{
		if (++i == rule->size)
			i = 0;
		if (check_philo_time(&philos[i], rule))
			break ;
		if (rule->max_eat_flag && check_philo_eat(rule))
			break ;
	}
}
