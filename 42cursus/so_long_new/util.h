#ifndef UTIL_H
# define UTIL_H

# define OK 0
# define ERROR 1

# include <stdio.h>
# include <stdlib.h>

void	ft_error(char *message);
size_t	ft_strlen(const char *str);
int		ft_stncmp(const char *s1, const char *s2, int n);
void	*ft_memcpy(void *dest, const void *src, int count);
void	*ft_calloc(int num, int size);

#endif
