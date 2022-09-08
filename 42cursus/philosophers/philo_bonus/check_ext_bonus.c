/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:21:57 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 15:21:58 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"
#include "util_bonus.h"
#include <pthread.h>
#include <signal.h>

static void	monitor_eat_die(t_rule *rule)
{
	int	i;

	i = -1;
	while (++i < rule->size)
		sem_wait(rule->sem_eats);
	sem_wait(rule->sem_print);
	i = -1;
	while (++i < rule->size)
		kill(rule->pids[i], SIGINT);
}

void	check_max_eat_die(t_rule *rule)
{
	pthread_t	pthread;

	if (rule->max_eat_flag)
	{
		if (pthread_create(&pthread, 0, (void *)monitor_eat_die, (void *)rule))
			ft_error("Error");
		if (pthread_detach(pthread))
			ft_error("Error");
	}
	return ;
}
