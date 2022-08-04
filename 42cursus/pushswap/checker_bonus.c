#include "checker_bonus.h"
#include "command_bonus.h"

static void	ft_operating(t_data *data, char *op)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		ft_command(data, PA);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		ft_command(data, PB);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		ft_command(data, SA);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		ft_command(data, SB);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ft_command(data, SS);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ft_command(data, RA);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		ft_command(data, RB);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		ft_command(data, RR);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		ft_command(data, RRA);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		ft_command(data, RRB);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		ft_command(data, RRR);
	else
		ft_error("Error");
}

static int	ft_is_sorted(t_stack *s)
{
	int		i;
	t_node	*node;

	i = 0;
	node = s->top;
	while (node)
	{
		if (i++ != node->pri)
			return (0);
		node = node->next;
	}
	return (1);
}

static void	ft_checking(t_data *data)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (op == NULL)
			break ;
		ft_operating(data, op);
		free(op);
	}
	if (ft_is_sorted(data->a) && data->b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char *av[])
{
	t_data	*data;

	if (ac < 2)
		return (0);
	ft_init(&data);
	ft_parse(ac, av, data->a);
	ft_checking(data);
	return (0);
}
