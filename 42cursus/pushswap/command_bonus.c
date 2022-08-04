#include "command_bonus.h"

void	ft_command(t_data *data, int cmd)
{
	t_stack	*s;

	if (cmd == PA || cmd == SA || cmd == RA || cmd == RRA)
		s = data->a;
	else
		s = data->b;
	if (cmd == SA || cmd == SB)
		ft_swap(s);
	else if (cmd == RA || cmd == RB)
		ft_rotate(s);
	else if (cmd == RRA || cmd == RRB)
		ft_rrotate(s);
	else if (cmd == PA)
		ft_push(data->a, data->b);
	else if (cmd == PB)
		ft_push(data->b, data->a);
}
