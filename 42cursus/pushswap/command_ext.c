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

int	ft_push(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (src->size)
	{
		if (src->size == 1)
			src->bottom = NULL;
		tmp = ft_pop(src);
		tmp->next = dst->top;
		if (dst->size == 0)
			dst->bottom = tmp;
		dst->top = tmp;
		dst->size++;
	}
	return (1);
}

int	ft_swap(t_stack *s)
{
	t_node	*tmp;

	if (s->size < 2)
		return (0);
	if (s->size == 2)
		s->bottom = s->top;
	tmp = s->top;
	s->top = tmp->next;
	tmp->next = s->top->next;
	s->top->next = tmp;
	return (1);
}

int	ft_rotate(t_stack *s)
{
	t_node	*tmp;

	if (s->size < 2)
		return (0);
	tmp = s->top;
	s->bottom->next = tmp;
	s->top = s->top->next;
	s->bottom = tmp;
	tmp->next = NULL;
	return (1);
}

int	ft_rrotate(t_stack *s)
{
	t_node	*tmp;
	int		i;

	if (s->size < 2)
		return (0);
	tmp = s->bottom;
	tmp->next = s->top;
	s->top = tmp;
	i = -1;
	tmp = s->top;
	while (++i < s->size - 1)
		tmp = tmp->next;
	s->bottom = tmp;
	s->bottom->next = NULL;
	return (1);
}
