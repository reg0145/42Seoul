/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:21:59 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 15:22:00 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"
#include "util_bonus.h"
#include <unistd.h>

int	init_rule(t_rule *rule, int *ag, int ac)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_EATS);
	rule->sem_forks = sem_open(SEM_FORKS, O_CREAT, 0644, ag[0]);
	rule->sem_print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	rule->sem_eats = sem_open(SEM_EATS, O_CREAT, 0644, 0);
	rule->pids = (int *)ft_calloc(ag[0], sizeof(int));
	if (rule->sem_print == SEM_FAILED || rule->sem_forks == SEM_FAILED \
		|| rule->sem_eats == SEM_FAILED || rule->pids == NULL)
		return (1);
	if (ac == 6)
	{
		rule->max_eat_flag = 1;
		rule->max_eat_count = ag[4];
	}
	rule->size = ag[0];
	rule->life_time = ag[1];
	rule->eat_time = ag[2];
	rule->sleep_time = ag[3];
	return (0);
}

int		init_philos(t_philosopher *philo, t_rule *rule, int *args)
{
	//sem_unlink(SEM_EAT);
	philo->rule = rule;
	philo->eat_count = args[4];
	/*
	philo->m_eat = sem_open(SEM_EATS, O_CREAT, 0644, args[0]);
	if (philo->m_eat == SEM_FAILED)
		return (1);
	*/
	return (0);
}

int	init(t_philosopher **philo, t_rule **rule, int ac, char **av)
{
	int		i;
	int		ag[5];

	*rule = (t_rule *)ft_calloc(1, sizeof(t_rule));
	*philo = (t_philosopher *)ft_calloc(1, sizeof(t_philosopher));
	if (*rule == NULL || *philo == NULL)
		return (1);
	i = 0;
	while (++i < ac)
	{
		ag[i - 1] = ft_atoi(av[i]);
		if (ag[i - 1] < 0)
			return (1);
	}
	if (init_rule(*rule, ag, ac) || init_philos(*philo, *rule, ag))
		return (1);
	return (0);
}
