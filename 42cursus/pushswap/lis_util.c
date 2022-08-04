#include <limits.h>

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_max_list(int *lst, int len)
{
	int	i;
	int	max;

	i = -1;
	max = INT_MIN;
	while (++i < len)
		if (max < lst[i])
			max = lst[i];
	return (max);
}
