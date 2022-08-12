/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:06:58 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/06 19:26:57 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_arg(const char *str)
{
	int	is_num;

	is_num = 0;
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (*str == '+' || *str == '-')
			str++;
		while (ft_isdigit(*str))
		{
			str++;
			is_num += 2;
		}
		if (is_num < 2 || *str == '+' || *str == '-')
			return (FAIL);
		is_num = 1;
		while (*str == ' ')
			str++;
	}
	if (is_num == 0)
		return (FAIL);
	return (OK);
}

static int	ft_set_stack_node_pri(t_stack	*s)
{
	t_node	*node;
	t_node	*move;

	node = s->top;
	while (node)
	{
		move = node->next;
		while (move)
		{
			if (node->v < move->v)
				move->pri++;
			else
				node->pri++;
			if (node->v == move->v)
				return (FAIL);
			move = move->next;
		}
		node = node->next;
	}
	return (OK);
}

static void	ft_free_split(char **data)
{
	int	i;

	i = -1;
	while (data[++i])
		free(data[i]);
	if (data)
		free(data);
}

void	ft_parse(int ac, char *av[], t_stack *a)
{
	int		i;
	int		j;
	char	**arg;

	i = 0;
	while (++i < ac)
	{
		if (ft_check_arg(av[i]))
			ft_error("Error");
		arg = ft_split(av[i], ' ');
		if (!arg)
			ft_error("Error");
		j = -1;
		while (arg[++j])
			ft_add_stack(a, ft_atoi(arg[j]));
		ft_free_split(arg);
	}
	if (ft_set_stack_node_pri(a))
		ft_error("Error");
}
