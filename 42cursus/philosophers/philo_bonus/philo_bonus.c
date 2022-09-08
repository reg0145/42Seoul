/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:22:07 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 15:22:08 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_life(t_philosopher *philo)
{
	long	time;
	t_rule	*rule;

	rule = philo->rule;
	if (philo->id % 2 == 0)
		uxsleep((double)rule->eat_time / 2);
	while (1)
	{
		sem_wait(rule->sem_forks);
		uxprintf(philo, "%ld %d has taken a fork\n");
		sem_wait(rule->sem_forks);
		uxprintf(philo, "%ld %d has taken a fork\n");
		time = get_passed_time(rule->s_time);
		philo->eat_time = time;
		philo_eat_count(philo);
		uxprintf(philo, "%ld %d is eating\n");
		uxsleep(rule->eat_time);
		sem_post(rule->sem_forks);
		sem_post(rule->sem_forks);
		uxprintf(philo, "%ld %d is sleeping\n");
		uxsleep(rule->sleep_time);
		uxprintf(philo, "%ld %d is thinking\n");
	}
}

void begin_philo_life(t_philosopher *philo, t_rule *rule)
{
	pthread_t	pthread;

	if (pthread_create(&pthread, 0, (void *)philo_life, (void *)philo))
		ft_error("Error");
	if (pthread_detach(pthread))
		ft_error("Error");
	check_philos_die(philo, rule);
}

int	begin(t_philosopher *philo, t_rule *rule)
{
	int	i;

	if (gettimeofday(&rule->s_time, 0) == -1)
		return (1);
	i = -1;
	while (++i < rule->size)
	{
		rule->pids[i] = fork();
		if (rule->pids[i] == 0)
		{
			philo->id = i + 1;
			begin_philo_life(philo, rule);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philosopher	*philo;
	t_rule			*rule;

	if (check_args(ac, av))
		ft_error("Error");
	if (init(&philo, &rule, ac, av))
		ft_error("Erorr");
	if (check_count(rule))
	{
		begin(philo, rule);
		check_max_eat_die(rule);
		wait_process(rule);
	}
	uxfree(philo, rule);
	while(1);
	return (0);
}
