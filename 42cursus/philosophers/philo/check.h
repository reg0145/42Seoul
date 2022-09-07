#ifndef CHECK_H
# define CHECK_H

# include "type.h"

int		check_args(int ac, char **av);
void	check_philos_die(t_philosopher *philos, t_rule *rule);
int		check_count(t_rule	*rule);

#endif
