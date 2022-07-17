#include "object.h"

void	ft_move_object(t_object *obj, t_move move)
{
	obj->x += move.x;
	obj->y += move.y;
}

void	ft_create_game_objects(t_objects *objs, t_map *map, void *mlx)
{
	if (ft_check_game_objects(objs, map))
		ft_error("[Error] Invalid objects of map");
	if (ft_check_objects_to_imgs(objs, mlx))
		ft_error("[Error] Objects to imgs");
}
