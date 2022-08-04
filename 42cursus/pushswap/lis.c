#include "lis.h"

static t_lis	*ft_find_lis(int *buf, int *arr, int len)
{
	int		i;
	int		j;
	int		max;
	t_lis	*lis;

	max = ft_max_list(buf, len);
	lis = (t_lis *)ft_calloc(1, sizeof(t_lis));
	if (!lis)
		ft_error("Error");
	lis->arr = (int *)ft_calloc(max, sizeof(int));
	if (!lis->arr)
		ft_error("Error");
	lis->size = max;
	j = max;
	i = len;
	while (--i >= 0)
	{
		if (buf[i] == max)
		{
			lis->arr[--j] = arr[i];
			max--;
		}
	}
	return (lis);
}

static int	*ft_calc_lis(int *arr, int len)
{
	int	i;
	int	j;
	int	*buf;

	buf = (int *)ft_calloc(len, sizeof(int));
	if (!buf)
		ft_error("Error");
	i = -1;
	while (++i < len)
		buf[i] = 1;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < i)
			if (arr[i] > arr[j])
				buf[i] = ft_max(buf[i], buf[j] + 1);
	}
	return (buf);
}

t_lis	*ft_lis(int *arr, int len)
{
	int		*buf;
	t_lis	*lis;

	buf = ft_calc_lis(arr, len);
	lis = ft_find_lis(buf, arr, len);
	free(buf);
	return (lis);
}
