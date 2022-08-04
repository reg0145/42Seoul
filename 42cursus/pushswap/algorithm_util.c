#include "command.h"
#include "push_swap.h"

int	ft_get_small_in_stack(t_stack *s)
{
	int		small;
	t_node	*node;

	small = s->top->pri;
	node = s->top;
	while (node)
	{
		if (small > node->pri)
			small = node->pri;
		node = node->next;
	}
	return (small);
}

int	ft_get_big_in_stack(t_stack *s)
{
	int		big;
	t_node	*node;

	big = s->top->pri;
	node = s->top;
	while (node)
	{
		if (big < node->pri)
			big = node->pri;
		node = node->next;
	}
	return (big);
}

void	ft_set_big_small(t_stack *s, int v)
{
	if (v > s->big)
		s->big = v;
	if (v < s->small)
		s->small = v;
}

int	ft_abs_plus(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	return (a + b);
}

void	ft_sort_stack(t_data *data)
{
	int		move;
	t_node	*node;

	node = data->a->top;
	if (node)
	{
		if (node->pri > data->a->size / 2)
		{
			move = data->a->size - node->pri;
			ft_loop_command(data, RA, move);
		}
		else
		{
			move = node->pri;
			ft_loop_command(data, RRA, move);
		}
	}
}
