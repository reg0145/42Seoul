#ifndef FT_MAP_H
# define FT_MAP_H

# include <stdlib.h>
# include "map.h"

typedef struct s_map {
	size_t	row;
	size_t	col;
	char	**data;
}	t_map;

typedef enum e_map_object {
	space	= '0',
	wall	= '1',
	collec	= 'C',
	escape	= 'E',
	player	= 'P',
}	t_map_object;

int		ft_create_map(t_map *map, char *str_map);
int		ft_parse_map(t_map *map, int fd);
void	ft_create_game_map(t_map *map, char *map_file);

#endif
