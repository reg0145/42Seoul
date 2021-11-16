/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:55:56 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/30 00:44:31 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq_header.h"

int	find_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void	ft_find_square(int **map, t_minfo *minfo)
{
	int	i;
	int	j;

	i = 1;
	while (i < minfo->row)
	{
		j = 1;
		while (j < minfo->col - 1)
		{
			if (map[i][j] && map[i - 1][j]
				&& map[i][j - 1] && map[i - 1][j - 1])
			{
				map[i][j] = find_min(map[i - 1][j - 1],
						map[i - 1][j], map[i][j - 1]) + 1;
				if (map[i][j] > minfo->max.val)
				{
					minfo->max.val = map[i][j];
					minfo->max.x = j;
					minfo->max.y = i;
				}
			}
			j++;
		}
		i++;
	}
}

void	ft_make_square(char *buf, t_minfo *minfo)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (i < minfo->max.val)
	{
		j = 0;
		while (j < minfo->max.val)
		{
			pos = minfo->max.y * minfo->col;
			pos = pos + minfo->max.x - i * minfo->col - j;
			buf[pos] = minfo->full;
			j++;
		}
		i++;
	}
}
