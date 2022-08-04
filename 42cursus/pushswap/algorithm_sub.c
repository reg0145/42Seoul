#include "push_swap.h"
#include "command.h"
#include "util.h"

void	ft_three_sort(t_data *data)
{
	int		flag;
	t_node	*node;

	flag = 0;
	node = data->a->top;
	if (node->pri > node->next->pri)
		flag |= 0x4;
	if (node->next->pri > node->next->next->pri)
		flag |= 0x2;
	if (node->pri > node->next->next->pri)
		flag |= 0x1;
	if (flag == 2 || flag == 4 || flag == 7)
		ft_command(data, SA);
	else if (flag == 3)
		ft_command(data, RRA);
	else if (flag == 5)
		ft_command(data, RA);
	if (flag == 2)
		ft_command(data, RA);
	if (flag == 7)
		ft_command(data, RRA);
}

void	ft_short_sort(t_data *data)
{
	t_node	*node;

	node = data->a->top;
	if (data->a->size == 1)
		return ;
	else if (data->a->size == 2)
	{
		if (node->pri > node->next->pri)
			ft_command(data, SA);
	}
	else
		ft_three_sort(data);
}

void	ft_short_greedy_algorithm(t_data *data)
{
	int	size;

	size = data->a->size;
	while (size-- > 3)
		ft_command(data, PB);
	ft_short_sort(data);
}
