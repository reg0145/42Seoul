#include "philosophers.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // usleep()
#include <sys/time.h>

void	uxprintf(t_philosopher *philos, char *say)
{
	pthread_mutex_lock(philos->rule->m_print);
	printf(say, get_passed_time(philos->rule->s_time), philos->id);
	pthread_mutex_unlock(philos->rule->m_print);
}

t_rule	*init_rule(int *args)
{
	int		i;
	t_rule	*rule;

	rule = (t_rule *)ft_calloc(1, sizeof(t_rule));
	if (rule == NULL)
		return (NULL);
	if (gettimeofday(&rule->s_time, NULL))
		return (NULL);
	rule->forks = (pthread_mutex_t *)ft_calloc(args[0],sizeof(pthread_mutex_t)); // 뮤텍스 포크 셋팅
	rule->m_print = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	rule->m_eat = (pthread_mutex_t *)ft_calloc(args[0], sizeof(pthread_mutex_t));
	if (rule->m_print == NULL || rule->forks == NULL || rule->m_eat == NULL)
		return (NULL);
	i = -1;
	while (++i < args[0])
	{
		if (pthread_mutex_init(&rule->forks[i], NULL))
			return (NULL);
		if (pthread_mutex_init(&rule->m_eat[i], NULL))
			return (NULL);
	}
	if (pthread_mutex_init(rule->m_print, NULL))
		return (NULL);
	rule->size = args[0];
	rule->life_time = args[1];
	rule->eat_time = args[2];
	rule->sleep_time = args[3];
	return (rule);
}

t_philosopher	*init_philos(t_rule *rule, int *args, int len)
{
	int				i;
	t_philosopher	*philos;

	philos = (t_philosopher *)ft_calloc(len, sizeof(t_philosopher));
	if (!philos)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		philos[i].id = i + 1;
		philos[i].rule = rule;
		philos[i].m_eat = &rule->m_eat[i];
	}
	if (len > 0)
	{
		i = 0;
		while (++i < args[0])
		{
			philos[i].right_fork = &rule->forks[i];
			philos[i].left_fork = &rule->forks[i - 1];
		}
		philos[0].right_fork = &rule->forks[0];
		philos[0].left_fork = &rule->forks[i - 1];
	}
	return (philos);
}

int	init(t_philosopher **philos, t_rule **rule, int ac, char **av)
{
	int		i;
	int		args[5];

	i = 0;
	while (++i < ac)
	{
		args[i - 1] = ft_atoi(av[i]);
		if (args[i - 1] < 0)
			return (FAIL);
	}
	*rule = init_rule(args); // rule 셋팅
	if (*rule == NULL)
		return (FAIL);
	*philos = init_philos(*rule, args ,args[0]);
	if (*philos == NULL)
		return (FAIL);
	return (OK);
}

void	philos_life(t_philosopher *philos)
{
	t_rule	*rule;
	long	time;

	rule = philos->rule;
	if (philos->id % 2 == 0)
		uxsleep((double)rule->eat_time / 2);
	while (1)
	{
		pthread_mutex_lock(philos->right_fork);
		uxprintf(philos, "%ld %d has taken a fork\n");
		pthread_mutex_lock(philos->left_fork);
		uxprintf(philos, "%ld %d has taken a fork\n");
		time = get_passed_time(rule->s_time);
		pthread_mutex_lock(philos->m_eat);
		philos->eat_time = time;
		pthread_mutex_unlock(philos->m_eat);
		uxprintf(philos, "%ld %d is eating\n");
		uxsleep(rule->eat_time);
		pthread_mutex_unlock(philos->right_fork);
		pthread_mutex_unlock(philos->left_fork);
		uxprintf(philos, "%ld %d is sleeping\n");
		uxsleep(rule->sleep_time);
		uxprintf(philos, "%ld %d is thinking\n");
	}
}

void	uxfree()
{

}

void	check_philos_die(t_philosopher *philos, t_rule *rule)
{
	int				i;
	long			philo_time;

	while (1)
	{
		i = -1;
		while (++i < rule->size)
		{
			philo_time = get_passed_time(rule->s_time);
			pthread_mutex_lock(philos[i].m_eat);
			philo_time = philo_time - philos[i].eat_time;
			pthread_mutex_unlock(philos[i].m_eat);
			if (philo_time >= rule->life_time)
			{
				pthread_mutex_lock(rule->m_print);
				printf("%ld %d died\n", philo_time, philos->id);
				return ;
			}
		}
	}
}

void	begin_philos_life(t_philosopher *philos, int len)
{
	int 		i;
	pthread_t	pthread;

	i = -1;
	while (++i < len)
	{
		// 마지막 필로가 홀수일 경우 늦게 실행
		if (i == len -1 && i % 2 == 0)
			usleep(philos->rule->eat_time / 2);
		// 여러 쓰레드는 실행되고 특정 쓰레드가 실행되지 않을 때 처리 방법은?
		if (pthread_create(&pthread, NULL, (void *)philos_life, (void*)&philos[i]))
			return ;
		// pthread는 할당이 되지 않으면 에러를 내뿜는다.
		if (pthread_detach(pthread))
			return ;
	}
}

int main (int ac, char **av)
{
	t_philosopher	*philos;
	t_rule			*rule;

	if (check_args(ac, av) || init(&philos, &rule, ac, av))
	{
		printf("Error");
		return (0);
	}
	begin_philos_life(philos, philos->rule->size);
	check_philos_die(philos, rule);
	while (1)
		continue ;
	uxfree();
}
