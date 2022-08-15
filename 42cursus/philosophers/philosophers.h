#ifndef PHIOSOPHERS_H
# define PHIOSOPHERS_H

# include "util.h"
# include "check.h"
# include <pthread.h>

# define FAIL 1
# define OK 0

typedef struct s_rule
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
	struct timeval	s_time;
	int				eat_time;
	int				life_time;
	int				sleep_time;
}	t_rule;

typedef struct s_philosopher
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				eat_count;
	t_rule			*rule;
}	t_philosopher;

#endif
