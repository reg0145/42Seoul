#include "event.h"

void	ft_update_object(t_game *game, t_map_object crash_obj)
{
	t_object	esc;

	if (crash_obj == wall)
		return ;
	else if (crash_obj == collec)
	{
		if (--game->objs.collec_num == 0)
		{
			esc = game->objs.escape;
			esc.img = ft_parse_xpm_to_img(game->mlx, XPM_ESCAPE_OPEN);
			ft_draw_object(game, esc, esc.x, esc.y);
			game->status = game_end;
		}
	}
	else if (crash_obj == escape)
		if (game->status == game_end)
			ft_exit_game(game);
	printf("movement : %d\n", ++game->objs.move_count);
}

void	ft_draw_player(t_game *game, t_map_object crash_obj, t_move move)
{
	t_object	*player;
	t_object	esc;

	player = &game->objs.player;
	esc = game->objs.escape;
	if (crash_obj == wall)
		return ;
	if (game->map.data[player->y][player->x] == escape)
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
	if (key == key_a)
		move.x--;
	else if (key == key_d)
		move.x++;
	else if (key == key_s)
		move.y++;
	else if (key == key_w)
		move.y--;
	return (move);
}

int	ft_key_press(int key, t_game *game)
{
	t_move			move;
	t_map_object	crash_obj;

	if (key == key_esc)
		ft_exit_game(game);
	if (key == key_a || key == key_d || key == key_w || key == key_s)
	{
		move = ft_parse_xy(key);
		crash_obj = ft_get_object(game, move);
		ft_draw_player(game, crash_obj, move);
		ft_update_object(game, crash_obj);
	}
}
