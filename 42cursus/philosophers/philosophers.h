#ifndef PHIOSOPHERS_H
# define PHIOSOPHERS_H

# include "util.h"
# include "check.h"
# include <pthread.h>

# define FAIL 1
# define OK 0

typedef struct s_rule
{
	int				size;
	long			eat_time;
	long			life_time;
	long			sleep_time;
	struct timeval	s_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*m_eat;
}	t_rule;

typedef struct s_philosopher
{
	int				id;
	int				eat_count;
	long			eat_time;
	t_rule			*rule;
	pthread_mutex_t	*m_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philosopher;

#endif
