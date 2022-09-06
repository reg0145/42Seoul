#include "philo_bonus.h"

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

void	philo_eat_count(t_philosopher *philo)
{
	if (philo->rule->max_eat_flag)
	{
		if (philo->eat_count > 0)
			philo->eat_count--;
		else if (philo->eat_count == 0)
		{
			philo->rule->max_eat_flag = 0;
			sem_post(philo->rule->sem_eats);
		}
	}
}

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

void ft_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
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

int	check_eat_count(t_rule	*rule)
{
	if (rule->max_eat_flag && rule->max_eat_count <= 0)
		return (0);
	return (1);
}

void	monitor_eat_die(t_rule *rule)
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

int	main(int ac, char **av)
{
	t_philosopher	*philo;
	t_rule			*rule;

	if (check_args(ac, av))
		ft_error("Error");
	if (init(&philo, &rule, ac, av))
		ft_error("Erorr");
	if (check_eat_count(rule))
	{
		begin(philo, rule);
		check_max_eat_die(rule);
		wait_process(rule);
	}
	uxfree(philo, rule);
	return (0);
}
