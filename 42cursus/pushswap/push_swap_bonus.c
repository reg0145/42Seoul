#include "Libft/libft.h"
#include "push_swap_bonus.h"
#include <stdio.h>

void	ft_init(t_data **data)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	(*data)->a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	(*data)->b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!*data || !(*data)->a || !(*data)->b)
		ft_error("Error");
}
