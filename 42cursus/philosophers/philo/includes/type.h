#ifndef TYPE_H
# define TYPE_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_rule
{
	int				size;
	long			eat_time;
	long			life_time;
	long			sleep_time;
	int				max_eat_flag;
	int				max_eat_count;
	int				eat_count;
	struct timeval	s_time;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*forks;
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
