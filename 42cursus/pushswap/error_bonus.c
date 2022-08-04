#include <stdlib.h>
#include <unistd.h>

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_error(char *msg)
{
	size_t	len;

	len = ft_strlen(msg);
	write(1, msg, len);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
