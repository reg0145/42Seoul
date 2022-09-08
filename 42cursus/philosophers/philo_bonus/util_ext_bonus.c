/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_ext_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:22:21 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 15:22:21 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "type_bonus.h"

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

void	uxfree(t_philosopher *philo, t_rule *rule)
{
	if (rule != NULL)
	{
		if (rule->sem_forks != NULL)
			sem_close(rule->sem_forks);
		if (rule->sem_eats != NULL)
			sem_close(rule->sem_eats);
		if (rule->sem_print != NULL)
			sem_close(rule->sem_print);
		if (rule->pids != NULL)
			free(rule->pids);
		free(rule);
	}
	if (philo != NULL)
	{
		if (philo->m_eat != NULL)
			sem_close(philo->m_eat);
		free(philo);
	}
}

void ft_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}
