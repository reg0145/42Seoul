/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:07:05 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/05 10:07:06 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	*ft_stack_to_list(t_stack *s)
{
	int		i;
	int		*arr;
	t_node	*node;

	arr = (int *)ft_calloc(s->size, sizeof(int));
	if (!arr)
		ft_error("Error");
	i = -1;
	node = s->top;
	while (++i < s->size)
	{
		arr[i] = node->pri;
		node = node->next;
	}
	return (arr);
}

int	ft_is_in_array(int *arr, int len, int v)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (v == arr[i])
			return (1);
	}
	return (0);
}

void	ft_add_stack(t_stack *s, int v)
{
	t_node	*n;
	t_node	*tmp;
	int		i;

	n = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!n)
		ft_error("Error");
	n->v = v;
	if (s->size == 0)
		s->top = n;
	else
	{
		i = 0;
		tmp = s->top;
		while (++i < s->size)
			tmp = tmp->next;
		tmp->next = n;
		s->bottom = n;
	}
	s->size++;
}
