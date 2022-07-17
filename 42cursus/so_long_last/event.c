/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:54:31 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/18 03:23:54 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_update_object(t_game *game, t_map_object crash_obj)
{
	t_object	esc;

	if (crash_obj == WALL)
		return ;
	else if (crash_obj == COLLEC)
	{
		if (--game->objs.collec_num == 0)
		{
			esc = game->objs.escape;
			esc.img = ft_parse_xpm_to_img(game->mlx, XPM_ESCAPE_OPEN);
			ft_draw_object(game, esc, esc.x, esc.y);
			game->status = GAME_END;
		}
	}
	else if (crash_obj == ESCAPE)
		if (game->status == GAME_END)
			ft_exit_game(game);
	printf("movement : %d\n", ++game->objs.move_count);
}

void	ft_draw_player(t_game *game, t_map_object crash_obj, t_move move)
{
	t_object	*player;
	t_object	esc;

	player = &game->objs.player;
	esc = game->objs.escape;
	if (crash_obj == WALL)
		return ;
	if (game->map.data[player->y][player->x] == ESCAPE)
		ft_draw_object(game, esc, esc.x, esc.y);
	else
		ft_draw_object(game, game->objs.space, player->x, player->y);
	ft_move_object(player, move);
	ft_draw_object(game, *player, player->x, player->y);
}

t_move	ft_parse_xy(int key)
{
	t_move	move;

	move.x = 0;
	move.y = 0;
	if (key == KEY_A)
		move.x--;
	else if (key == KEY_D)
		move.x++;
	else if (key == KEY_S)
		move.y++;
	else if (key == KEY_W)
		move.y--;
	return (move);
}

int	ft_key_press(int key, t_game *game)
{
	t_move			move;
	t_map_object	crash_obj;

	if (key == KEY_ESC)
		ft_exit_game(game);
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
	{
		move = ft_parse_xy(key);
		crash_obj = ft_get_object(game, move);
		ft_draw_player(game, crash_obj, move);
		ft_update_object(game, crash_obj);
	}
	return (0);
}
