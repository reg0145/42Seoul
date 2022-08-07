/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:07:42 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/07 12:04:44 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

static void	ft_print_cmd(int cmd)
{
	if (cmd == PA)
		write(1, "pa\n", 3);
	else if (cmd == PB)
		write(1, "pb\n", 3);
	else if (cmd == SA)
		write(1, "sa\n", 3);
	else if (cmd == SB)
		write(1, "sb\n", 3);
	else if (cmd == RA)
		write(1, "ra\n", 3);
	else if (cmd == RB)
		write(1, "rb\n", 3);
	else if (cmd == RRA)
		write(1, "rra\n", 4);
	else if (cmd == RRB)
		write(1, "rrb\n", 4);
}

void	ft_command(t_data *data, int cmd)
{
	t_stack	*s;
	int		success;

	success = 1;
	if (cmd == PA || cmd == SA || cmd == RA || cmd == RRA)
		s = data->a;
	else
		s = data->b;
	if (cmd == SA || cmd == SB)
		success = ft_swap(s);
	else if (cmd == RA || cmd == RB)
		success = ft_rotate(s);
	else if (cmd == RRA || cmd == RRB)
		success = ft_rrotate(s);
	else if (cmd == PA)
		ft_push(data->a, data->b);
	else if (cmd == PB)
		ft_push(data->b, data->a);
	if (success)
		ft_print_cmd(cmd);
}

void	ft_loop_command(t_data *data, int cmd, int cnt)
{
	int	i;

	i = -1;
	while (++i < cnt)
		ft_command(data, cmd);
}
