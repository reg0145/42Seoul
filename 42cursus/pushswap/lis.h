#ifndef LIS_H
# define LIS_H

# include <stdlib.h>
# include "libft.h"
# include "error.h"

typedef struct s_lis
{
	int	*arr;
	int	size;
}	t_lis;

int	ft_max(int a, int b);
int	ft_max_list(int *lst, int len);

#endif
