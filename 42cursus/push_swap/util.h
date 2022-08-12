/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:07:09 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/05 10:07:10 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "push_swap.h"

int		*ft_stack_to_list(t_stack *s);
int		ft_max(int a, int b);
int		ft_max_list(int *lst, int len);
int		ft_get_small_in_stack(t_stack *s);
int		ft_get_big_in_stack(t_stack *s);
int		ft_is_in_array(int *arr, int len, int v);
void	ft_set_big_small(t_stack *s, int v);
int		ft_abs_plus(int a, int b);
void	ft_sort_stack(t_data *data);

#endif
