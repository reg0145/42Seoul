/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:22:15 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 15:22:15 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_BONUS_H
# define TYPE_BONUS_H

# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>

# define SEM_PRINT "print"
# define SEM_FORKS "forks"
# define SEM_EATS "eats"
# define SEM_EAT "eat"

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
