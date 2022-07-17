/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:57:51 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/18 03:29:02 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdio.h>
# include <stdlib.h>

void	ft_error(char *message);
int		ft_strlen(const char *str);
int		ft_stncmp(const char *s1, const char *s2, int n);
void	*ft_memcpy(void *dest, const void *src, int count);
void	*ft_calloc(int num, int size);

#endif
