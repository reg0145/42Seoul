/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:28:35 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/27 14:31:38 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
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
	char	*str;
	int		len;

	len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	return (ft_strcpy(str, src));
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (arr == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		(arr + i)->size = ft_strlen(av[i]);
		(arr + i)->str = av[i];
		(arr + i)->copy = ft_strdup(av[i]);
		i++;
	}
	arr[i] = (t_stock_str){0, 0, 0};
	return (arr);
}
