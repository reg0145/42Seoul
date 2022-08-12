/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:07:59 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/06 19:25:30 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "algorithm.h"
#include "util.h"

void	ft_last_to_b(t_data *data, t_lis *lis)
{
	int		v;
	int		len;
	t_node	*tmp;

	len = data->a->size;
	tmp = data->a->top;
	while (len--)
	{
		v = tmp->pri;
		tmp = tmp->next;
		if (ft_is_in_array(lis->arr, lis->size, v))
			ft_command(data, RA);
		else
			ft_command(data, PB);
	}
}

void	ft_a_to_b(t_data *data, t_lis *lis)
{
	int		v;
	int		len;
	int		pivot;
	t_node	*tmp;

	pivot = data->a->size / 3;
	tmp = data->a->top;
	len = data->a->size;
	while (len--)
	{
		v = tmp->pri;
		tmp = tmp->next;
		if (ft_is_in_array(lis->arr, lis->size, v))
			ft_command(data, RA);
		else if (v < pivot)
		{
			ft_command(data, PB);
			ft_command(data, RB);
		}
		else if (v > pivot && v <= pivot * 2)
			ft_command(data, PB);
		else
			ft_command(data, RA);
	}
	ft_last_to_b(data, lis);
}

void	ft_process_command(t_data *data, t_cost min_cost)
{
	if (min_cost.a > 0)
		ft_loop_command(data, RA, min_cost.a);
	else
		ft_loop_command(data, RRA, -min_cost.a);
	if (min_cost.b > 0)
		ft_loop_command(data, RB, min_cost.b);
	else
		ft_loop_command(data, RRB, -min_cost.b);
	ft_command(data, PA);
}

void	ft_b_to_a(t_data *data)
{
	int		i;
	t_stack	*a;
	t_cost	min_cost;

	i = 0;
	a = data->a;
	a->big = ft_get_big_in_stack(data->a);
	a->small = ft_get_small_in_stack(data->a);
	while (i < data->b->size)
	{
		ft_min_pa_cost(&min_cost, data);
		ft_process_command(data, min_cost);
		ft_set_big_small(a, data->a->top->pri);
	}
}

void	ft_greedy_algorithm(t_data *data, t_lis *lis)
{
	if (data->a->size > 5)
		ft_a_to_b(data, lis);
	else
		ft_short_greedy_algorithm(data);
	ft_b_to_a(data);
	ft_sort_stack(data);
}
