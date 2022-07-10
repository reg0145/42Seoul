#include <stdlib.h>

int	ft_len(char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

int	ft_stncmp(const char *s1, const char *s2, int n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	int				i;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (us1[i] != '\0' && us2[i] != '\0' && i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (i == n)
		return (0);
	else
		return (us1[i] - us2[i]);
}

void	*ft_memcpy(void *dest, const void *src, int count)
{
	unsigned char	*d_tmp;
	unsigned char	*s_tmp;

	if (dest == NULL && src == NULL)
		return (NULL);
	d_tmp = (unsigned char *)dest;
	s_tmp = (unsigned char *)src;
	while (count--)
		*d_tmp++ = *s_tmp++;
	return (dest);
}

void	*ft_calloc(int num, int size)
{
	char	*temp;
	int	i;
	int	total;

	total = num * size;
	temp = (char *)malloc(sizeof(char) * total);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < total)
		temp[i++] = 0;
	return ((void *)temp);
}
