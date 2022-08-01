#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define OK 0
# define FAIL 1

# include "libft.h"

typedef struct	s_node
{
	int	v;
	int	pri;
	struct s_node *next;
}	t_node;

typedef struct	s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

void	ft_error(char *message);
void	ft_add_stack(t_stack *s, int data);
void	ft_parse(int ac, char *av[], t_stack *a);
#endif
