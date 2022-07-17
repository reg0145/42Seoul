#include "check.h"


int	ft_check_game_object(t_objects *objs, char obj, int row, int col)
{
	if (obj == player && objs->player.x == 0 && objs->player.y == 0)
	{
		objs->player.x = col;
		objs->player.y = row;
	}
	else if (obj == escape && objs->escape.x == 0 && objs->escape.y == 0)
	{
		objs->escape.x = col;
		objs->escape.y = row;
	}
	else if (obj == collec)
		objs->collec_num++;
	else if (obj != wall && obj != space && obj != '\0')
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
		while (++col < (int)map->col)
			ft_check_game_object(objs, map->data[row][col], row, col);
	}
	return (OK);
}
