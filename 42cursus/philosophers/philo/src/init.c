#include "../includes/type.h"
#include "../includes/util.h"
#include <sys/time.h>

void	init_rule_ext(t_rule *rule, int *ag, int ac)
{
	if (ac == 6)
	{
		rule->max_eat_flag = 1;
		rule->max_eat_count = ag[4];
	}
	gettimeofday(&rule->s_time, 0);
	rule->eat_count = ag[0];
	rule->size = ag[0];
	rule->life_time = ag[1];
	rule->eat_time = ag[2];
	rule->sleep_time = ag[3];
}

t_rule	*init_rule(int *ag, int ac)
{
	int		i;
	t_rule	*rule;

	rule = (t_rule *)ft_calloc(1, sizeof(t_rule));
	if (rule == NULL)
		return (NULL);
	rule->forks = (pthread_mutex_t *)ft_calloc(ag[0], sizeof(pthread_mutex_t));
	rule->m_eat = (pthread_mutex_t *)ft_calloc(ag[0], sizeof(pthread_mutex_t));
	if (rule->forks == 0 || rule->m_eat == 0)
		return (NULL);
	i = -1;
	while (++i < ag[0])
		if (pthread_mutex_init(&rule->forks[i], NULL) \
			|| pthread_mutex_init(&rule->m_eat[i], NULL))
			return (NULL);
	if (pthread_mutex_init(&rule->m_print, 0))
		return (NULL);
	init_rule_ext(rule, ag, ac);
	return (rule);
}

void	init_philos_ext(t_rule *rule, t_philosopher *philos, int *args, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		philos[i].id = i + 1;
		philos[i].rule = rule;
		philos[i].m_eat = &rule->m_eat[i];
		philos[i].eat_count = args[4];
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
}

t_philosopher	*init_philos(t_rule *rule, int *args)
{
	int				len;
	t_philosopher	*philos;

	len = args[0];
	philos = (t_philosopher *)ft_calloc(len, sizeof(t_philosopher));
	if (philos == NULL)
		return (NULL);
	init_philos_ext(rule, philos, args, len);
	return (philos);
}

int	init(t_philosopher **philos, t_rule **rule, int ac, char **av)
{
	int		i;
	int		ag[5];

	i = 0;
	while (++i < ac)
	{
		ag[i - 1] = ft_atoi(av[i]);
		if (ag[i - 1] < 0)
			return (1);
	}
	*rule = init_rule(ag, ac);
	if (*rule == NULL)
		return (1);
	*philos = init_philos(*rule, ag);
	if (*philos == NULL)
		return (1);
	return (0);
}
