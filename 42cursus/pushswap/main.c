#include "Libft/libft.h"
#include "push_swap.h"

void	ft_init(t_data **data)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	(*data)->a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	(*data)->b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!*data && !(*data)->a && !(*data)->b)
		ft_error("Error");
}

int main(int ac, char *av[])
{
	t_data	*data;

	if (ac < 2)
		return 0;
	// init
	ft_init(&data);
	// 파싱
	ft_parse(ac, av, data->a);
	// 알고리즘
	return (0);
}
