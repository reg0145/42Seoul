# include "util.h"
# inlcude <pthread.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int	id;
	int	left_fork;
	int	right_fork;
	int	status;
	int	updated_time;
	int	eat_count;
}	t_philosopher;

typedef struct s_time
{
	int	eat;
	int	sleep;
	int	think;
}	t_time;

typedef struct s_table
{
	t_philosopher	*philos;
	t_limit			limit;
	char			*error;
}	t_table;

typedef enum e_status
{
	NONE,
	EATING,
	SLEEPING,
	THINKING,
}	t_status;

void	print_status(t_philosopher *philos, char *status)
{
	pthread_mutex_lock();
	printf("%d %s");
	pthread_mutex_unlock();
}

void	ft_check_philos_died(t_philosopher *philos)
{
	while (1)
	{
		if (philos->status == NONE)
			continue ;
		now = gettimeofday();
		else if (philos->status == EATING)
			limit = gettimeofday();
		else if (philos->status == SLEEPING)
			limit = 
		else if (philos->status == THINKING)

	}
}



int main(int ac, char **av)
{
	t_philosopher		*philosophers;
	t_philosopher_time	*philosopher_time;

	while ()
	ft_parse(ac, av);
}