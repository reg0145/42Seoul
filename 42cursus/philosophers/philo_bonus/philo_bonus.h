/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:22:10 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 15:22:11 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "type_bonus.h"
# include "util_bonus.h"
# include "init_bonus.h"
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

void	wait_process(t_rule *rule);
void	kill_all(t_rule *rule);

#endif
