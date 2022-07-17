#ifndef CHECK_H
# define CHECK_H

# include "game.h"

size_t	ft_check_map_file_name(char *str_map);
int	ft_check_map_rect(t_map *map);
int	ft_check_map_walls(t_map *map);
int	ft_check_map_after_reading(char *map_file, int *fd);
int	ft_check_objects_to_imgs(t_objects *objs, void *mlx);
int	ft_check_game_objects(t_objects *objs, t_map *map);

#endif
