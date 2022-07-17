#ifndef EVENT_H
# define EVENT_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# include "game.h"

int		ft_key_press(int key, t_game *game);
void	ft_move_object(t_object *obj, t_move move);
void	ft_update_object(t_game *game, t_map_object crash_obj);

#endif
