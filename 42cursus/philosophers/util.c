# include <unistd.h>

void	*ft_calloc(size_t num, size_t size)
{
	char	*step;
	size_t	i;
	size_t	total;

	total = num * size;
	step = (char *)malloc(sizeof(char) * total);
	if (step == NULL)
		return (NULL);
	i = 0;
	while (i < total)
		step[i++] = 0;
	return ((void *)step);
}
