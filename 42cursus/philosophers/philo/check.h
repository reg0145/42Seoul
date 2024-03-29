/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:25:13 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 14:49:38 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "type.h"

int		check_args(int ac, char **av);
void	check_philos_die(t_philosopher *philos, t_rule *rule);
int		check_count(t_rule	*rule);

#endif
