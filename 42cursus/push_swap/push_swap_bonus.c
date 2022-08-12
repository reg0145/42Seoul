/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:06:56 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/06 19:27:02 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_init(t_data **data)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!*data)
		ft_error("Error");
	(*data)->a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	(*data)->b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!*data || !(*data)->a || !(*data)->b)
		ft_error("Error");
}
