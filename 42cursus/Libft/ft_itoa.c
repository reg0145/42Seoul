/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:26:06 by donghyuk          #+#    #+#             */
/*   Updated: 2021/12/01 00:42:43 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	ft_str_swap(char *str)
{
	int		size;
	int		idx;
	char	temp;

	size = 0;
	while (str[size] != '\0')
		size++;
	idx = 0;
	while (idx < size)
	{
		temp = str[size - 1];
		str[size - 1] = str[idx];
		str[idx] = temp;
		idx++;
		size--;
	}
}*/

static unsigned int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*p;
	int				len;
	unsigned int	num;
	int				i;

	len = ft_numlen(n);
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	num = n;
	i = 0;
	if (n < 0)
	{
		p[0] = '-';
		num = -num;
		i = 1;
	}
	while (len-- > i)
	{
		p[len] = "0123456789"[num % 10];
		num /= 10;
	}
	return (p);
}
