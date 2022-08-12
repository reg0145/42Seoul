#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>

void	*ft_calloc(size_t num, size_t size);
double	get_passed_time(struct timeval s);
long	uxsleep(double ms);
int		ft_atoi(const char *s);
#endif
