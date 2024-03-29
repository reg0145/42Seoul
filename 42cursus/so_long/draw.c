/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:55:26 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/18 03:20:46 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_object(t_game *game, t_object obj, int x, int y)
{
	x = x * OBJECT_IMG_SIZE;
	y = y * OBJECT_IMG_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, obj.img, x, y);
}

void	ft_draw_move_object(t_game *game, t_object *obj)
{
	int	x;
	int	y;

	x = obj->x * OBJECT_IMG_SIZE;
	y = obj->y * OBJECT_IMG_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, obj->img, x, y);
}

void	ft_draw_map(t_game *game)
{
	int	col;
	int	row;

	row = -1;
	while (++row < (int)game->map.row)
	{
		col = -1;
		while (++col < (int)game->map.col)
		{
			if (game->map.data[row][col] == WALL)
				ft_draw_object(game, game->objs.wall, col, row);
			else
				ft_draw_object(game, game->objs.space, col, row);
			if (game->map.data[row][col] == PLAYER)
				ft_draw_object(game, game->objs.player, col, row);
			else if (game->map.data[row][col] == ESCAPE)
				ft_draw_object(game, game->objs.escape, col, row);
			else if (game->map.data[row][col] == COLLEC)
				ft_draw_object(game, game->objs.collec, col, row);
		}
	}
}

void	ft_draw_game(t_game *game)
{
	t_object	player;

	player = game->objs.player;
	ft_draw_object(game, game->objs.space, player.x, player.y);
	ft_draw_move_object(game, &game->objs.player);
}
