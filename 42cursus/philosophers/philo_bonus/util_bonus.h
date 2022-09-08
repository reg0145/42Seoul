/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:22:19 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 15:22:19 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_BONUS_H
# define UTIL_BONUS_H

# include <unistd.h>
# include "type_bonus.h"

void	*ft_calloc(size_t num, size_t size);
long	get_passed_time(struct timeval s);
long	uxsleep(double ms);
void	uxprintf(t_philosopher *philos, char *say);
void	uxfree(t_philosopher *philos, t_rule *rule);
int		ft_atoi(const char *s);
int		ft_isdigit(char	c);
size_t	ft_strlen(const char *s);
void	ft_error(char *msg);
#endif
