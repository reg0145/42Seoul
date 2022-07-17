/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:55:31 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/18 03:36:15 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_game_object(t_objects *objs, char obj, int row, int col)
{
	if (obj == PLAYER)
	{
		if (objs->player.x != 0)
			return (ERROR);
		objs->player.x = col;
		objs->player.y = row;
	}
	else if (obj == ESCAPE)
	{
		if (objs->escape.x != 0)
			return (ERROR);
		objs->escape.x = col;
		objs->escape.y = row;
	}
	else if (obj == COLLEC)
		objs->collec_num++;
	else if (obj != WALL && obj != SPACE && obj != '\0')
		return (ERROR);
	return (OK);
}

int	ft_check_game_objects(t_objects *objs, t_map *map)
{
	int		col;
	int		row;
	int		checks;

	checks = 0;
	row = -1;
	while (++row < (int)map->row)
	{
		col = -1;
		while (++col < (int)map->col)
			ft_check_game_object(objs, map->data[row][col], row, col);
	}
	if (objs->collec_num == 0 || objs->player.x == 0 || objs-> escape.x == 0)
		return (ERROR);
	return (OK);
}
