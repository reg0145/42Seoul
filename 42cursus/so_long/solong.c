/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:16:21 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/10 16:16:23 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_error(char *message) {
	printf("%s\n", message);
	exit(EXIT_SUCCESS);
}

t_map	*ft_create_map(char *str_map, int map_size) {
	t_map	*map;
	int		row;

	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (map == NULL)
		ft_error("The error is : Can't allocate memory");
	row = ft_get_row(str_map);
	map->val = str_map;
	map->row = row;
	map->size = map_size;
	return (map);
}

int	ft_continue_read_and_size_up(int fd, char **map, int pre_size) {
	char	*temp;
	int		cur_size;
	int		read_size;

	cur_size = pre_size;
	temp = *map;
	cur_size *= 2;
	*map = ft_memcpy((char *)ft_calloc(sizeof(char), cur_size), map, pre_size);
	free(temp);
	if (map == NULL)
		ft_error("The error is : Can't allocate memory");
	read_size = read(fd, &map[pre_size], cur_size - pre_size);
	return (read_size);
}

t_map	*ft_get_map(char *map_file) {
	int		fd;
	char	*str_map;
	t_map	*map;
	int		map_size;

	fd = open(map_file, O_RDONLY);
	if (fd < 1)
		ft_error("The error is : No such file");
	str_map = (char *)ft_calloc(sizeof(char), BUFFER_SIZE);
	if (str_map == NULL)
		ft_error("The error is : Can't allocate memory");
	map_size = read(fd, str_map, BUFFER_SIZE);
	while (map_size != 0 && map_size % BUFFER_SIZE == 0) {
		map_size = ft_continue_read_and_size_up(fd, &str_map, map_size);
	}
	map = ft_create_map(str_map, map_size);
	return (map);
}

void	ft_check_map_file_name(char *str_map) {
	int	len;

	len = ft_len(str_map);
	if (len < 5)
		ft_error("The error is : Invalid Map Name");
	if (ft_stncmp(&str_map[len - 4], ".ber", 4) != 0)
		ft_error("The error is : Invalid Map Name");
}

int	ft_check_map_rect(t_map *map) {
	char	*str_map;
	int		pivot_col;
	int		cur_col;

	str_map = map->val;
	pivot_col = ft_get_col(str_map);
	while (*str_map != '\0') {
		cur_col = ft_get_col(str_map);
		str_map += cur_col + 1;
		if (cur_col != pivot_col)
			return (1);
	}
	return (0);
}

int	ft_check_map_walls(t_map *map) {
	int		col;
	int		idx;
	int		end_col_idx;
	char	*str_map;

	str_map = map->val;
	if (map->row < 3)
		return (1);
	col = ft_get_col(str_map);
	idx = 1;
	while (idx < col) {
		end_col_idx = (map->row - 1) * (col + 1) + idx;
		if (str_map[idx - 1] != wall || str_map[end_col_idx] != wall)
			return (1);
		idx++;
	}
	idx = 1;
	while (idx <= map->row) {
		if (str_map[col * (idx - 1)] != wall || str_map[(col - 1) * idx])
			return (1);
		idx ++;
	}
	return (0);
}

int	ft_check_map_objects(t_map *map) {
	(void)map;
	return (0);
}

void	ft_create_game(char *map_file) {
	t_map *map;

	ft_check_map_file_name(map_file);
	map = ft_get_map(map_file);
	if (ft_check_map_rect(map))
		ft_error("The error is : Map must be rectangle");
	if (ft_check_map_walls(map))
		ft_error("The error is : Map should be surrounded by walls");
	/*
	if (!ft_check_map_objects(map))
		ft_error("The error is : Map must have a required objects");
	*/

}

int	main(int argc, char *args[]) {
	if (argc < 2)
		ft_error("please input : ./solong map_name.ber");
	ft_create_game(args[1]);
	return (0);
}
