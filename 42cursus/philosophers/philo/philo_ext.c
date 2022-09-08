/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:44:48 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 14:58:03 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <pthread.h>

void	philo_eat_count(t_philosopher *philo)
{
	if (philo->rule->max_eat_flag)
	{
		philo->eat_count--;
		if (philo->eat_count > 0)
			return ;
		else if (philo->eat_count == 0)
		{
			philo->eat_count--;
			pthread_mutex_lock(&philo->rule->m_eat_cnt);
			philo->rule->eat_count--;
			pthread_mutex_unlock(&philo->rule->m_eat_cnt);
		}
	}
}
