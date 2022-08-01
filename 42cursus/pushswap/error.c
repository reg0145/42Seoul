#include <unistd.h>
#include "libft.h"

void	ft_error(char *message)
{
	size_t	len;

	len = ft_strlen(message);
	write(1, message, len);
	write(1, "\n", 1);
}
