#ifndef SOLONG_H
# define SOLONG_H
# define BUFFER_SIZE 1024

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx_opengl/mlx.h"

typedef struct s_map {
	char	*val;
	int		row;
	int		col;
	int		size;
}	t_map;

typedef enum e_map_object {
	space = '0',
	wall = '1',
	collection = 'C',
	escape = 'E',
	start = 'P',
	enemy = 'X'
}	t_map_object;

void	*mlx_init();
int		ft_len(char *str);
int		ft_stncmp(const char *s1, const char *s2, int n);
void	*ft_memcpy(void *dest, const void *src, int count);
void	*ft_calloc(int num, int size);
int		ft_get_col(char *str);
int		ft_get_row(char *str);
#endif
