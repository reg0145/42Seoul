#ifndef COMMAND_H
# define COMMAND_H

# include "push_swap.h"

typedef enum e_command
{
	PA,
	PB,
	SA,
	SB,
	RA,
	RB,
	RRA,
	RRB,
	SS,
	RR,
	RRR
}	t_command;

void	ft_command(t_data *data, int cmd);
void	ft_loop_command(t_data *data, int cmd, int cnt);
void	*ft_push(t_stack *dst, t_stack *src);
int		ft_swap(t_stack *s);
int		ft_rotate(t_stack *s);
int		ft_rrotate(t_stack *s);
#endif
