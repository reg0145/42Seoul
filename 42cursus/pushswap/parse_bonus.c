#include "push_swap_bonus.h"
#include "Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_check_arg(const char *str)
{
	int	int_cnt;

	int_cnt = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '+' || *str == '-')
			str++;
		while (ft_isdigit(*str))
		{
			int_cnt++;
			str++;
		}
	}
	if (int_cnt == 0)
		return (FAIL);
	return (OK);
}

static int	ft_set_stack_node_pri(t_stack	*s)
{
	t_node	*node;
	t_node	*move;

	node = s->top;
	while (node)
	{
		move = node->next;
		while (move)
		{
			if (node->v < move->v)
				move->pri++;
			else
				node->pri++;
			if (node->v == move->v)
				return (FAIL);
			move = move->next;
		}
		node = node->next;
	}
	return (OK);
}

static void	ft_free_split(char **data)
{
	int	i;

	i = -1;
	while (data[++i])
		free(data[i]);
	if (data)
		free(data);
}

void	ft_parse(int ac, char *av[], t_stack *a)
{
	int		i;
	int		j;
	char	**arg;

	i = 0;
	while (++i < ac)
	{
		if (ft_check_arg(av[i]))
			ft_error("Error");
		arg = ft_split(av[i], ' ');
		if (!arg)
			ft_error("Error");
		j = -1;
		while (arg[++j])
			ft_add_stack(a, ft_atoi(arg[j]));
		ft_free_split(arg);
	}
	if (ft_set_stack_node_pri(a))
		ft_error("Error");
}
