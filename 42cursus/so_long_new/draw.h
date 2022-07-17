#ifndef DRAW_H
# define DRAW_H

# include "game.h"

void	ft_draw_object(t_game *game, t_object obj, int x, int y);
void	ft_draw_move_object(t_game *game, t_object *obj);
void	ft_draw_map(t_game *game);

#endif
