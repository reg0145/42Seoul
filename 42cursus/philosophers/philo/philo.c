/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:25:21 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 14:25:21 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "type.h"

int	philo_eat(t_philosopher *philo)
{
	t_rule	*rule;
	long	time;

	rule = philo->rule;
	pthread_mutex_lock(philo->right_fork);
	if (uxprintf(philo, "%ld %d has taken a fork\n"))
		return (FAIL);
	pthread_mutex_lock(philo->left_fork);
	if (uxprintf(philo, "%ld %d has taken a fork\n"))
		return (FAIL);
	time = get_passed_time(rule->s_time);
	pthread_mutex_lock(philo->m_eat);
	philo->eat_time = time;
	philo_eat_count(philo);
	pthread_mutex_unlock(philo->m_eat);
	if (uxprintf(philo, "%ld %d is eating\n"))
		return (FAIL);
	uxsleep(rule->eat_time);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (OK);
}

void	philos_life(t_philosopher *philo)
{
	t_rule	*rule;

	rule = philo->rule;
	if (philo->id % 2 == 0)
		uxsleep((double)rule->eat_time / 2);
	while (1)
	{
		if (philo_eat(philo))
			break ;
		if (uxprintf(philo, "%ld %d is sleeping\n"))
			break ;
		uxsleep(rule->sleep_time);
		if (uxprintf(philo, "%ld %d is thinking\n"))
			break ;
	}
}

int	begin_philos_life(t_philosopher *philos, int len)
{
	int			i;

	i = -1;
	while (++i < len)
	{
		if (i == len - 1 && i % 2 == 0)
			usleep(philos->rule->eat_time / 2);
		if (pthread_create(&philos[i].pthread, 0, (void *)philos_life \
			, (void *)&philos[i]))
			return (1);
		if (pthread_detach(philos[i].pthread))
			return (1);
	}
	return (0);
}

void	philo_join(t_philosopher *philos, t_rule *rule)
{
	int	i;

	i = -1;
	while (++i < rule->size)
		pthread_join(philos[i].pthread, NULL);
}

int	main(int ac, char **av)
{
	t_philosopher	*philos;
	t_rule			*rule;

	rule = NULL;
	philos = NULL;
	if (check_args(ac, av) || init(&philos, &rule, ac, av))
	{
		printf("Error");
		uxfree(philos, rule);
		return (1);
	}
	if (check_count(rule))
	{
		if (begin_philos_life(philos, philos->rule->size))
			printf("Error");
		check_philos_die(philos, rule);
		philo_join(philos, rule);
	}
	uxfree(philos, rule);
	return (0);
}
