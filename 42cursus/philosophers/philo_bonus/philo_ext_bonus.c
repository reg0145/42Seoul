/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ext_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:22:13 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 15:22:13 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"
#include <signal.h>
#include <sys/wait.h>

void	kill_all(t_rule *rule)
{
	int	i;

	i = -1;
	while (++i < rule->size)
		kill(rule->pids[i], SIGINT);
}

void	wait_process(t_rule *rule)
{
	int	status;

	waitpid(-1, &status, 0);
	kill_all(rule);
}
