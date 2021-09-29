/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:40:42 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/30 00:44:33 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq_header.h"

int	ft_atoi_n(char *str, int n)
{
	int			i;
	long long	num;

	num = 0;
	i = 0;
	if (!('0' <= str[i] && str[i] <= '9'))
		return (0);
	while (i <= n - 4)
	{
		if ('0' <= str[i] && str[i] <= '9')
			num = num * 10 + str[i] - '0';
		else
			return (0);
		if (num > 2147483647)
			return (0);
		i++;
	}
	return ((int)num);
}

int	ft_strlen(char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (i);
		i++;
	}
	return (i + 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		len;

	len = ft_strlen(src, '\0');
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	return (ft_strcpy(result, src));
}

void	ft_error(void)
{
	write(1, "map_error\n", 11);
}
