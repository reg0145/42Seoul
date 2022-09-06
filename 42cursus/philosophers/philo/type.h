#ifndef TYPE_H
# define TYPE_H

# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_rule
{
	int				size;
	pid_t			*pids;
	long			eat_time;
	long			life_time;
	long			sleep_time;
	int				max_eat_flag;
	int				max_eat_count;
	sem_t			*sem_eats;
	sem_t			*sem_print;
	sem_t			*sem_forks;
	struct timeval	s_time;
}	t_rule;

typedef struct s_philosopher
{
	int		id;
	int		eat_count;
	long	eat_time;
	t_rule	*rule;
	sem_t	*m_eat;
}	t_philosopher;

#endif
