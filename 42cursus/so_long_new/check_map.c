#include "check.h"

size_t	ft_check_map_file_name(char *str_map)
{
	size_t	len;

	len = ft_strlen(str_map);
	if (len < 5)
		return (ERROR);
	if (ft_stncmp(&str_map[len - 4], ".ber", 4) != 0)
		return (ERROR);
	return (OK);
}

int	ft_check_map_rect(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < map->row)
		if (ft_strlen(map->data[i++]) != map->col)
			return (ERROR);
	return (OK);
}

int	ft_check_map_walls(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->col)
		if (map->data[0][i] != wall || map->data[map->row - 1][i] != wall)
			return (ERROR);
	i = 0;
	while (++i < map->row - 1)
		if (map->data[i][0] != wall || map->data[i][map->col - 1] != wall)
			return (ERROR);
	return (OK);
}

int	ft_check_map_after_reading(char *map_file, int *fd)
{
	*fd = open(map_file, O_RDONLY);
	if (!*fd)
		return (ERROR);
	return (OK);
}

int	ft_check_objects_to_imgs(t_objects *objs, void *mlx)
{
	t_object	*obj;

	obj = &objs->player;
	obj->img = ft_parse_xpm_to_img(mlx, XPM_PLAYER);
	obj = &objs->wall;
	obj->img = ft_parse_xpm_to_img(mlx, XPM_WALL);
	obj = &objs->space;
	obj->img = ft_parse_xpm_to_img(mlx, XPM_SPACE);
	obj = &objs->collec;
	obj->img = ft_parse_xpm_to_img(mlx, XPM_COLLECT);
	obj = &objs->escape;
	obj->img = ft_parse_xpm_to_img(mlx, XPM_ESCAPE_CLOSE);
	if (!objs->player.img || !objs->escape.img || !objs->space.img
		|| !objs->collec.img || !objs->wall.img)
		return (ERROR);
	return (OK);
}
