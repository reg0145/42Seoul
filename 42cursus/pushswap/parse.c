#include "push_swap.h"
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
	t_node	*pviot;
	t_node	*move;

	pviot = s->top;
	while (pviot)
	{
		move = pviot->next;
		while (move)
		{
			if (pviot->v < move->v)
				move->pri++;
			if (pviot->v == move->v)
				return (FAIL);
			move = move->next;
		}
		pviot = pviot->next;
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
		if (ft_set_stack_node_pri(a))
			ft_error("Error");
		ft_free_split(arg);
	}
	/* 출력 확인
	node = a->top;
	while (node)
	{
		printf("%d", node->v);
		node = node->next;
	}
	*/
}
