#include "Libft/libft.h"
#include "push_swap.h"
#include "util.h"
#include <stdio.h>

t_lis	*ft_get_lis(t_stack *s)
{
	int		*arr;
	t_lis	*lis;

	arr = ft_stack_to_list(s);
	lis = ft_lis(arr, s->size);
	free(arr);
	return (lis);
}

void	ft_init(t_data **data)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	(*data)->a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	(*data)->b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!*data || !(*data)->a || !(*data)->b)
		ft_error("Error");
}

int	main(int ac, char *av[])
{
	t_data	*data;
	t_lis	*lis;

	if (ac < 2)
		return (0);
	ft_init(&data);
	ft_parse(ac, av, data->a);
	lis = ft_get_lis(data->a);
	ft_greedy_algorithm(data, lis);
	return (0);
}
