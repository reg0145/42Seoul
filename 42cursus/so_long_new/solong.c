/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:16:21 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/15 04:11:17 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_error(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
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

void	*ft_parse_xpm_to_img(void *mlx, char *xpm_path, int *x, int *y) {
	void	*img;

	img = mlx_xpm_file_to_image(mlx, xpm_path, x, y);
	if (!img)
		return (NULL);
	return (img);
}

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

int	ft_check_game_object(t_objects *objs, char obj, int row, int col) {
	if (obj == player && objs->player.x != 0 && objs->player.y != 0)
	{
		objs->player.x = col;
		objs->player.y = row;
	}
	else if (obj == escape && objs->escape[0].x != 0 && objs->escape[0].y != 0)
	{
		objs->escape[0].x = col;
		objs->escape[0].y = row;
	}
	else if (obj == collec)
		objs->collec_num++;
	else if (obj != wall && obj != space &&  obj != '\0')
		return (ERROR);
	return (OK);
}

int	ft_check_game_objects(t_objects *objs, t_map *map)
{
	int		col;
	int		row;
	char	obj;
	int		checks;

	checks = 0;
	row = -1;
	while (++row < (int)map->row)
	{
		col = -1;
		while (++col < (int)map->col) {
			ft_check_game_object(objs, map->data[row][col], row, col);
		}
	}
	return (OK);
}

int	ft_check_map_after_reading(char *map_file, int *fd) {
	 *fd = open(map_file, O_RDONLY);
	 if (!*fd)
	 	return (ERROR);
	return (OK);
}

int	ft_check_objects_to_imgs(t_objects *objs, void *mlx) {
	t_object *obj;

	obj = &objs->player;
	obj->img = ft_parse_xpm_to_img(mlx, XPM_PLAYER, &obj->x, &obj->y);
	obj = &objs->wall;
	obj->img = ft_parse_xpm_to_img(mlx, XPM_WALL, &obj->x, &obj->y);
	obj = &objs->space;
	obj->img = ft_parse_xpm_to_img(mlx, XPM_SPACE, &obj->x, &obj->y);
	obj = &objs->collec;
	obj->img = ft_parse_xpm_to_img(mlx, XPM_COLLECT, &obj->x, &obj->y);
	obj = &objs->escape[0];
	obj->img = ft_parse_xpm_to_img(mlx, XPM_ESCAPE_OPEN, &obj->x, &obj->y);
	obj = &objs->escape[1];
	obj->img = ft_parse_xpm_to_img(mlx, XPM_ESCAPE_CLOSE, &obj->x, &obj->y);
	if (!objs->player.img || !objs->escape[0].img || !objs->space.img
		|| !objs->collec.img || !objs->escape[1].img || !objs->wall.img )
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

void	ft_create_game_objects(t_objects *objs, t_map *map, void *mlx)
{
	if (ft_check_game_objects(objs, map))
		ft_error("[Error] Invalid objects of map");
	if (ft_check_objects_to_imgs(objs, mlx))
		ft_error("[Error] Objects to imgs");
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
	*p_game = game;
}

void	ft_create_game_window(t_game *game) {
	mlx_new_window(game->mlx, game->map.col * 32, \
		game->map.row * 32, "so_long");
}

void	ft_create_game(char *map_file)
{
	t_game	*game;

	ft_create_game_init(&game);
	ft_create_game_map(&game->map, map_file);
	ft_create_game_objects(&game->objs, &game->map, game->mlx);
	ft_create_game_window(&game);
}

int	main(int argc, char *args[])
{
	if (argc < 2)
		ft_error("please input : ./solong map_name.ber");
	ft_create_game(args[1]);
	return (OK);
}
