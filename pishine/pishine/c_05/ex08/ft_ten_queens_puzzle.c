/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:45:11 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/25 14:55:11 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	g_cnt;

int		ft_check_rule(int qen_col, int rows, int *queens);
void	ft_solve(int qen_row, int *queens);

int	ft_abs(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

void	print_queens(int *queens)
{
	int		i;
	char	ch;

	i = -1;
	while (++i < 10)
	{
		ch = queens[i] + '0';
		write(1, &ch, 1);
	}
	write(1, "\n", 1);
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	i;

	i = 0;
	g_cnt = 0;
	while (i < 10)
		queens[i++] = 0;
	ft_solve(0, queens);
	return (g_cnt);
}

void	ft_solve(int qen_row, int *queens)
{
	int	qen_col;

	if (qen_row == 10)
	{
		g_cnt += 1;
		print_queens(queens);
		return ;
	}
	qen_col = 0;
	while (qen_col < 10)
	{
		if (ft_check_rule(qen_col, qen_row, queens))
		{
			queens[qen_row] = qen_col;
			ft_solve(qen_row + 1, queens);
		}
		qen_col++;
	}
}

int	ft_check_rule(int qen_col, int qen_row, int *queens)
{
	int	row;

	row = 0;
	while (row < qen_row)
	{
		if (queens[row] == qen_col)
			return (0);
		if (ft_abs(row - qen_row) == ft_abs(qen_col - queens[row]))
			return (0);
		row++;
	}
	return (1);
}
