/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:08:06 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/06 19:24:44 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "util.h"

static int	ft_find_v(t_stack *s, int v)
{
	int		idx;
	t_node	*tmp;

	idx = 0;
	tmp = s->top;
	while (tmp)
	{
		if (tmp->pri == v)
			break ;
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}

static int	ft_find_between_v(t_stack *a, int v)
{
	int		i;
	int		cost;
	int		min_of_max;
	t_node	*a_node;

	i = 0;
	cost = 0;
	a_node = a->top;
	min_of_max = a->big;
	while (a_node)
	{
		if (v < a_node->pri && min_of_max >= a_node->pri)
		{
			min_of_max = a_node->pri;
			cost = i;
		}
		i += 1;
		a_node = a_node->next;
	}
	return (cost);
}

static int	ft_cost_into_stack(t_stack *s, int v)
{
	int		cost;

	if (v > s->big || v < s->small)
		cost = ft_find_v(s, s->small);
	else
		cost = ft_find_between_v(s, v);
	if (cost > s->size / 2)
		cost = -(s->size - cost);
	return (cost);
}

int	ft_cost_b(t_stack *s, int idx)
{
	int	cost;

	if (idx > s->size / 2)
		cost = -(s->size - idx);
	else
		cost = idx;
	return (cost);
}

void	ft_min_pa_cost(t_cost *min_cost, t_data *data)
{
	int		i;
	t_cost	cost;
	t_node	*b_node;

	i = 0;
	min_cost->all = INT_MAX;
	b_node = data->b->top;
	while (b_node)
	{
		cost.a = ft_cost_into_stack(data->a, b_node->pri);
		cost.b = ft_cost_b(data->b, i++);
		cost.all = ft_abs_plus(cost.a, cost.b);
		if (min_cost->all > cost.all)
			*min_cost = cost;
		b_node = b_node->next;
	}
}
