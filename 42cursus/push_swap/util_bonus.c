/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:07:03 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/05 10:07:04 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
