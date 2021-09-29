/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:42:35 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/30 00:44:32 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq_header.h"

int	ft_set_malloc(int	***map, t_minfo *minfo)
{
	int	i;

	*map = (int **)malloc(sizeof(int *) * minfo->row);
	if (!*map)
		return (0);
	i = 0;
	while (i < minfo->row)
	{
		(*map)[i] = (int *)malloc(sizeof(int) * minfo->col);
		if ((*map)[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_char_to_int(int *map, char *buf, t_minfo *minfo)
{
	int	i;

	i = 0;
	while (i < minfo->col)
	{
		if (buf[i] == minfo->empty)
			map[i] = 1;
		else if (buf[i] == minfo->block)
			map[i] = 0;
		i++;
	}
}

void	ft_set_max(char *buf, t_minfo *minfo, int row)
{
	int	i;

	i = 0;
	while (i < minfo->col)
	{
		if (buf[i] == minfo->empty && minfo->max.val == -1)
		{
			minfo->max.val = 1;
			minfo->max.x = i;
			minfo->max.y = row;
		}
		i++;
	}
}

void	ft_set_value(int **map, char *buf, t_minfo *minfo)
{
	int		row;

	row = 0;
	minfo->max.val = -1;
	while (row < minfo->row)
	{
		ft_char_to_int(map[row], buf + (row * minfo->col), minfo);
		if (minfo->max.val == -1)
			ft_set_max(buf + (row * minfo->col), minfo, row);
		row++;
	}
}

void	ft_set_map(int	***map, char *buf, t_minfo *minfo)
{
	int	i;

	if (!ft_set_malloc(map, minfo))
		return ;
	ft_set_value(*map, buf, minfo);
	ft_find_square(*map, minfo);
	ft_make_square(buf, minfo);
	i = 0;
	while (i < minfo->row)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}
