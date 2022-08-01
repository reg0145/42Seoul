#include "Libft/libft.h"
#include "push_swap.h"

t_node	*ft_pop(t_stack *s)
{
	t_node	*tmp;

	tmp = s->top;
	s->top = s->top->next;
	s->size--;
	return (tmp);
}

void	*ft_push(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (src->size)
	{
		tmp = ft_pop(src);
		tmp -> next = dst->top;
		dst->top = tmp;
		dst->size++;
	}
}

void	ft_swap(t_stack *s)
{
	t_node	*tmp;

	if (s->size < 2)
		return ;
	if (s->size == 2)
		s->bottom = s->top;
	tmp = s->top;
	s->top = tmp->next;
	tmp->next = s->top->next;
	s->top->next = tmp;
}

void	ft_rotate(t_stack *s) {
	t_node	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->top;
	s->bottom->next = tmp;
	s->top = s->top->next;
}

void	ft_rrotate(t_stack *s) {
	t_node	*tmp;
	int		i;

	if (s->size < 2)
		return ;
	tmp = s->bottom;
	tmp->next = s->top;
	s->top = tmp;
	i = -1;
	tmp = s->top;
	while (++i < s->size - 1)
		tmp = tmp->next;
	s->bottom = tmp;
}
