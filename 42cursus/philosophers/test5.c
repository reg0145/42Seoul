#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // usleep()
#include <pthread.h>
#include <sys/time.h>

#define OK 0
#define FAIL 1

typedef struct s_time
{
	int	life;
	int	eat;
	int	sleep;
	int	think;
}	t_time;

typedef struct s_rule
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_lock[3];
	t_time	time;
	struct timeval s_time;
	int		flag;
	char	*error;
}	t_rule;

typedef struct s_philosopher
{
	int	id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int	updated_time;
	int	eat_count;
	int	flag;
	t_rule *rule;
}	t_philosopher;

typedef enum e_status
{
	NONE,
	EATING,
	SLEEPING,
	THINKING,
}	t_status;

typedef enum e_flag
{
	EVEN = 0x01,
	ODD  = 0x02,
	LIVE = 0x04,
	LOOP,
	EXIT
}	t_flag;

int	init(t_rule **rule, t_philosopher **philos, t_time time, int cnt)
{
	int	i;

	*rule = (t_rule *)ft_calloc(1, sizeof(t_rule));
	if (!*rule)
		return (FAIL);
	*philos = (t_philosopher *)ft_calloc(cnt, sizeof(t_philosopher));
	if (!(*philos))
		return (FAIL);
	(*rule)->forks = (pthread_mutex_t *)ft_calloc(cnt, sizeof(pthread_mutex_t));
	if (!(*rule)->forks)
		return (FAIL);
	i = -1;
	while (++i < cnt)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].rule = *rule;
	}
	i = -1;
	while (++i < cnt)
		pthread_mutex_init(&((*rule)->forks[i]) , NULL);
	if (cnt > 0)
	{
		i = 0;
		while (++i < cnt)
		{
			(*philos)[i].right_fork = &((*rule)->forks[i]);
			(*philos)[i].left_fork = &((*rule)->forks[i - 1]);
		}
		(*philos)[0].right_fork = &((*rule)->forks[0]);
		(*philos)[0].left_fork = &((*rule)->forks[i - 1]);
	}
	(*rule)->time = time;
	(*rule)->flag |= LIVE;
	gettimeofday(&(*rule)->s_time, NULL);
	pthread_mutex_init(&((*rule)->mutex_lock[0]), NULL);
	pthread_mutex_init(&((*rule)->mutex_lock[1]), NULL);
	pthread_mutex_init(&((*rule)->mutex_lock[2]), NULL);
	return (OK);
}

void	life_cycle(t_philosopher *philos)
{
	t_rule	*rule;
	int		flag;
	int		who;

	rule = philos->rule;
	if (philos->id % 2 == 0)
		uxsleep((double)rule->time.eat / 2);
	while (rule->flag & LIVE)
	{
		pthread_mutex_lock(philos->right_fork);
		pthread_mutex_lock(philos->left_fork);
		printf("%d %d is eating\n", get_passed_time(rule->s_time), philos->id);
		uxsleep(rule->time.eat);
		pthread_mutex_unlock(philos->right_fork);
		pthread_mutex_unlock(philos->left_fork);
		printf("%d %d is sleeping\n", get_passed_time(rule->s_time), philos->id);
		uxsleep(rule->time.sleep);
		printf("%d %d is thinking\n", get_passed_time(rule->s_time), philos->id);
	}
}

int main (void)
{
	int				len = 5;
	t_rule			*rule;
	t_philosopher	*philos;
	pthread_t		p_thread[len];

	t_time time;

	time.life = 410;
	time.eat = 200;
	time.sleep = 200;
	if (init(&rule, &philos, time, len))
		return (1);
	int i = -1;
	while (++i < len)
	{
		if (i == len -1 && i % 2 == 0)
			usleep(rule->time.eat / 2);
		pthread_create(&p_thread[i], NULL, (void *)life_cycle, (void*)&philos[i]);
		pthread_detach(p_thread[i]);
	}
	usleep(rule->time.eat / 2);
	sleep(10);
	while (1)
		continue ;
}
