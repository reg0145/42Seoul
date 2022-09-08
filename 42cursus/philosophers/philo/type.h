/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:25:26 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 14:25:52 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <pthread.h>
# include <sys/time.h>

# define DIE 1

typedef enum e_return_type
{
	OK	= 0,
	FAIL
}	t_return_type;

typedef struct s_rule
{
	int				size;
	int				status;
	long			eat_time;
	int				eat_count;
	long			life_time;
	long			sleep_time;
	int				max_eat_flag;
	int				max_eat_count;
	pthread_mutex_t	m_die;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_eat_cnt;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*m_eat;
	struct timeval	s_time;
}	t_rule;

typedef struct s_philosopher
{
	int				id;
	int				eat_count;
	long			eat_time;
	t_rule			*rule;
	pthread_t		pthread;
	pthread_mutex_t	*m_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philosopher;

#endif
