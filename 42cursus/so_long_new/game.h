#ifndef GAME_H
# define GAME_H
# define BUFFER_SIZE 1024

# include "event.h"
# include "object.h"
# include "map.h"
# include "util.h"
# include "minilibx_opengl/mlx.h"

typedef struct s_game {
	t_objects	objs;
	t_map		map;
	void		*win;
	void		*mlx;
	int			status;
}	t_game;

typedef enum e_game_status {
	game_end = 1,
	game_run = 0
}	t_game_status;

void	ft_run_game(t_game *game);
void	ft_start_game(char *map_file);
int		ft_exit_game(t_game *game);
void	ft_create_game_init(t_game **p_game);

#endif
