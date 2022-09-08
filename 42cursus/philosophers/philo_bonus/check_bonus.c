/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:21:54 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 15:21:54 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"
#include "util_bonus.h"
#include <stdio.h>
#include <stdlib.h>

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

void	check_philos_die(t_philosopher *philo, t_rule *rule)
{
	long	cur_time;
	long	philo_eat_time;

	while (1)
	{
		philo_eat_time = philo->eat_time;
		cur_time = get_passed_time(rule->s_time);
		if (cur_time - philo_eat_time >= rule->life_time)
		{
			sem_wait(rule->sem_print);
			printf("%ld %d died\n", cur_time, philo->id);
			exit(1);
		}
	}
}

int	check_count(t_rule	*rule)
{
	if (rule->size == 0)
		return (0);
	if (rule->max_eat_flag && rule->max_eat_count <= 0)
		return (0);
	return (1);
}

void	philo_eat_count(t_philosopher *philo)
{
	if (philo->rule->max_eat_flag)
	{
		philo->eat_count--;
		if (philo->eat_count > 0)
			return ;
		else if (philo->eat_count == 0)
		{
			philo->rule->max_eat_flag = 0;
			sem_post(philo->rule->sem_eats);
		}
	}
}
