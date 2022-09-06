#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include "type.h"

void	*ft_calloc(size_t num, size_t size);
long	get_passed_time(struct timeval s);
long	uxsleep(double ms);
void	uxprintf(t_philosopher *philos, char *say);
int		ft_atoi(const char *s);
int		ft_isdigit(char	c);
size_t	ft_strlen(const char *s);

#endif
