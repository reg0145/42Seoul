#ifndef SOLONG_H
# define SOLONG_H
# define BUFFER_SIZE 1024

# define OK 0
# define ERROR 1

# define XPM_PLAYER "./imgs/player.xpm"
# define XPM_SPACE "./imgs/space.xpm"
# define XPM_WALL "./imgs/wall.xpm"
# define XPM_GROUND "./imgs/ground.xpm"
# define XPM_ESCAPE_OPEN "./imgs/escape_opened.xpm"
# define XPM_ESCAPE_CLOSE "./imgs/escape_closed.xpm"
# define XPM_COLLECT "./imgs/collect.xpm"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define ESC 53
# define ENTER 36

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx_opengl/mlx.h"

typedef struct s_object
{
	int		x;
	int		y;
	void	*img;
}	t_object;

typedef struct s_map {
	size_t	row;
	size_t	col;
	char	**data;
}	t_map;

typedef	struct s_objects {
	t_object	player;
	t_object	escape[2];
	t_object	collec;
	t_object	wall;
	t_object	space;
	int			collec_num;
}	t_objects;

typedef struct s_game {
	t_map		map;
	t_objects	objs;
	void		*mlx;
}	t_game;

typedef enum e_map_object {
	space	= '0',
	wall	= '1',
	collec	= 'C',
	escape	= 'E',
	player	= 'P',
}	t_map_object;

void	*mlx_init();
size_t	ft_strlen(const char *str);
int		ft_stncmp(const char *s1, const char *s2, int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dest, const void *src, int count);
void	*ft_calloc(int num, int size);
int		ft_get_col(char *str);
int		ft_get_row(char *str);
#endif
