#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // usleep()
#include <pthread.h>


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
	pthread_mutex_t	mutex_lock[2];
	t_time	time;
	int		flag;
	char	*error;
}	t_rule;

typedef struct s_philosopher
{
	int	id;
	pthread_mutex_t	**left_fork;
	pthread_mutex_t	**right_fork;
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

void	action(pthread_mutex_t *mutex, char *str, int id)
{
	pthread_mutex_lock(mutex);
	printf(str, get_current_time(), id);
	pthread_mutex_unlock(mutex);
}

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
		pthread_mutex_init(((*rule)->forks + i) , NULL);
		(*philos)[i].id = i + 1;
		(*philos)[i].rule = *rule;
		if (i % 2 == 0)
			(*philos)[i].flag = ODD;
		else
			(*philos)[i].flag = EVEN;
	}
	if (cnt > 1)
	{
		i = 0;
		while (++i < cnt)
		{
			(*philos)[i].right_fork = &((*rule)->forks) + i;
			(*philos)[i].left_fork = &((*rule)->forks) + i - 1;
		}
		(*philos)[0].right_fork = &((*rule)->forks);
		(*philos)[0].left_fork = &((*rule)->forks) + i - 1;
	}
	(*rule)->time = time;
	(*rule)->flag |= LIVE;
	// 뮤텍스
	pthread_mutex_init(&((*rule)->mutex_lock[0]), NULL);
	return (OK);
}

void	life_cycle(t_philosopher *philos)
{
	t_rule	*rule;
	int		flag;
	int		who;

	rule = philos->rule;
	while ((rule->flag & philos->flag) == 0)
		continue ;
	while (rule->flag & LIVE)
	{
		pthread_mutex_lock(*(philos->left_fork));
		pthread_mutex_lock(*(philos->right_fork));
		action(&(rule->mutex_lock[0]), "%ld %d is eating\n", philos->id);
		pthread_mutex_unlock(*(philos->left_fork));
		pthread_mutex_unlock(*(philos->right_fork));
		usleep(rule->time.eat);
		action(&(rule->mutex_lock[0]), "%ld %d is sleeping\n", philos->id);
		usleep(rule->time.sleep);
		action(&(rule->mutex_lock[0]), "%ld %d is thinking\n", philos->id);
	}
}

int main (void)
{
	int			len = 1;
	t_rule			*rule;
	t_philosopher	*philos;
	pthread_t	p_thread[len];

	t_time time;

	time.life = 600;
	time.eat = 300;
	time.sleep = 300;
	printf("start");
	if (init(&rule, &philos, time, len))
		return (1);
	int i = -1;
	while (++i < len)
		pthread_create(&p_thread[i], NULL, (void *)life_cycle, (void*)&philos[i]);
	while (++i < len)
		pthread_detach(p_thread[i]);
	sleep(2);
	rule->flag |= EVEN;
	usleep(rule->time.eat);
	rule->flag |= ODD;
	sleep(10);
	rule->flag ^= LIVE;
}
