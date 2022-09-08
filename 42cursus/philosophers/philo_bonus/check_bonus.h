/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:21:56 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 15:21:56 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BONUS_H
# define CHECK_BONUS_H

# include "type_bonus.h"

int		check_args(int ac, char **av);
void	check_philos_die(t_philosopher *philos, t_rule *rule);
int		check_count(t_rule	*rule);
void	philo_eat_count(t_philosopher *philos);
void	check_max_eat_die(t_rule *rule);

#endif
