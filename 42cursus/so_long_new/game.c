/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:39:20 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/16 17:57:47 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_run_game(t_game *game)
{
	int	map_col;
	int	map_row;

	map_col = game->map.col * OBJECT_IMG_SIZE;
	map_row = game->map.row * OBJECT_IMG_SIZE;
	game->win = mlx_new_window(game->mlx, map_col, map_row, "solong");
	if (!game->win)
		ft_error("[Fail] Create window");
	ft_draw_map(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, ft_key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, ft_exit_game, game);
	//mlx_loop_hook(game->mlx, ft_loop, game);
	mlx_loop(game->mlx);
}

void	ft_start_game(char *map_file)
{
	t_game	*game;

	ft_create_game_init(&game);
	ft_create_game_map(&game->map, map_file);
	ft_create_game_objects(&game->objs, &game->map, game->mlx);
	ft_run_game(game);
}

int	ft_exit_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	exit(0);
}

void	ft_create_game_init(t_game **p_game)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error("[Error] Can't allocate memory");
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("[Error] Can't allocate memory");
	game->objs.move_count = 0;
	*p_game = game;
}
