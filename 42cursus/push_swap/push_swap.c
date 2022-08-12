/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:06:51 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/07 12:04:48 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_lis	*ft_get_lis(t_stack *s)
{
	int		*arr;
	t_lis	*lis;

	arr = ft_stack_to_list(s);
	lis = ft_lis(arr, s->size);
	free(arr);
	return (lis);
}

void	ft_init(t_data **data)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!*data)
		ft_error("Error");
	(*data)->a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	(*data)->b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!(*data)->a || !(*data)->b)
		ft_error("Error");
}

int	main(int ac, char *av[])
{
	t_data	*data;
	t_lis	*lis;

	if (ac < 2)
		return (0);
	ft_init(&data);
	ft_parse(ac, av, data->a);
	lis = ft_get_lis(data->a);
	if (lis->size == data->a->size)
		return (0);
	ft_greedy_algorithm(data, lis);
	return (0);
}
