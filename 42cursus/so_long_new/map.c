#include "map.h"

t_map_object	ft_get_object(t_game *game, t_move move)
{
	int				obj_x;
	int				obj_y;
	t_map_object	obj;
	t_object		*player;

	player = &game->objs.player;
	obj_x = player->x + move.x;
	obj_y = player->y + move.y;
	obj = (t_map_object)game->map.data[obj_y][obj_x];
	return (obj);
}

int	ft_create_map(t_map *map, char *str_map)
{
	map->data = ft_split(str_map, '\n');
	if (!map->data || !map->data[0])
		return (ERROR);
	map->col = ft_strlen(map->data[0]);
	map->row = 0;
	while (map->data[map->row] != NULL)
		map->row++;
	if (map->col < 3 || map->row < 3)
		return (ERROR);
	return (OK);
}

int	ft_parse_map(t_map *map, int fd)
{
	char	*buf;
	char	*str_map;
	int		size;

	buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	str_map = (char *)ft_calloc(sizeof(char), 1);
	if (!buf || !str_map)
		return (ERROR);
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = 0;
		str_map = ft_strjoin(str_map, buf);
		if (!str_map)
			return (ERROR);
		if (size < BUFFER_SIZE)
			break ;
	}
	if (ft_create_map(map, str_map))
		return (ERROR);
	return (OK);
}

void	ft_create_game_map(t_map *map, char *map_file)
{
	int	fd;

	if (ft_check_map_file_name(map_file))
		ft_error("[Error] Invalid name of map");
	if (ft_check_map_after_reading(map_file, &fd))
		ft_error("[Error] Can't read the file");
	if (ft_parse_map(map, fd))
		ft_error("[Error] Can't parse map");
	if (ft_check_map_rect(map))
		ft_error("[Error] Map must be rectangle");
	if (ft_check_map_walls(map))
		ft_error("[Error] Map should be surrounded by walls");
}
