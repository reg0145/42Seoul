#ifndef OBJECT_H
# define OBJECT_H

# define OBJECT_IMG_SIZE 32

typedef struct s_move
{
	int	x;
	int	y;
}	t_move;

typedef struct s_object
{
	int		x;
	int		y;
	void	*img;
}	t_object;

typedef	struct s_objects {
	t_object	player;
	t_object	escape;
	t_object	collec;
	t_object	wall;
	t_object	space;
	int			collec_num;
	int			move_count;
}	t_objects;

void	ft_move_object(t_object *obj, t_move move);
void	ft_create_game_objects(t_objects *objs, t_map *map, void *mlx);

#endif
