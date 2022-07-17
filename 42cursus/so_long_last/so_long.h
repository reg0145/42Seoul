/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:57:46 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/18 03:31:06 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1024
# define OBJECT_IMG_SIZE 32

# define XPM_PLAYER "./imgs/player.xpm"
# define XPM_SPACE "./imgs/space.xpm"
# define XPM_WALL "./imgs/wall.xpm"
# define XPM_GROUND "./imgs/ground.xpm"
# define XPM_ESCAPE_OPEN "./imgs/escape_opened.xpm"
# define XPM_ESCAPE_CLOSE "./imgs/escape_closed.xpm"
# define XPM_COLLECT "./imgs/collect.xpm"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define OK 0
# define ERROR 1

# include <stdlib.h>
# include "./mlx/mlx.h"

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

typedef struct s_objects
{
	t_object	player;
	t_object	escape;
	t_object	collec;
	t_object	wall;
	t_object	space;
	int			collec_num;
	int			move_count;
}	t_objects;

typedef struct s_map
{
	int		row;
	int		col;
	char	**data;
}	t_map;

typedef struct s_game
{
	t_objects	objs;
	t_map		map;
	void		*win;
	void		*mlx;
	int			status;
}	t_game;

typedef enum e_game_status
{
	GAME_RUN = 0,
	GAME_END
}	t_game_status;

typedef enum e_map_object
{
	SPACE	= '0',
	WALL	= '1',
	COLLEC	= 'C',
	ESCAPE	= 'E',
	PLAYER	= 'P'
}	t_map_object;

typedef enum e_event_key
{
	KEY_A	= 0,
	KEY_S	= 1,
	KEY_D	= 2,
	KEY_W	= 13,
	KEY_ESC	= 53
}	t_event_key;

char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
void			ft_error(char *message);
int				ft_strlen(const char *str);
int				ft_stncmp(const char *s1, const char *s2, int n);
void			*ft_memcpy(void *dest, const void *src, int count);
void			*ft_calloc(int num, int size);
int				ft_check_map_file_name(char *str_map);
int				ft_check_map_rect(t_map *map);
int				ft_check_map_walls(t_map *map);
int				ft_check_map_after_reading(char *map_file, int *fd);
int				ft_check_objects_to_imgs(t_objects *objs, void *mlx);
int				ft_check_game_objects(t_objects *objs, t_map *map);
void			ft_draw_object(t_game *game, t_object obj, int x, int y);
void			ft_draw_move_object(t_game *game, t_object *obj);
void			ft_draw_map(t_game *game);
void			*ft_parse_xpm_to_img(void *mlx, char *xpm_path);
int				ft_key_press(int key, t_game *game);
void			ft_move_object(t_object *obj, t_move move);
void			ft_update_object(t_game *game, t_map_object crash_obj);
void			ft_move_object(t_object *obj, t_move move);
void			ft_create_game_objects(t_objects *objs, t_map *map, void *mlx);
int				ft_create_map(t_map *map, char *str_map);
int				ft_parse_map(t_map *map, int fd);
void			ft_create_game_map(t_map *map, char *map_file);
void			ft_run_game(t_game *game);
void			ft_start_game(char *map_file);
int				ft_exit_game(t_game *game);
void			ft_create_game_init(t_game **p_game);
t_map_object	ft_get_object(t_game *game, t_move move);

#endif
