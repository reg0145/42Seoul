/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:26:06 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/25 11:40:49 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
}

static unsigned int	ft_numlen(int n)
{
	unsigned int	num;
	unsigned int	result;

	num = n;
	result = 1;
	if (n < 0)
	{
		num = -num;
		result++;
	}
	while (num > 9)
	{
		num = num / 10;
		result++;
	}
	return (result);
}

static void	ft_itoa_sub(unsigned int n, char *p)
{
	if (n > 9)
		ft_itoa_sub(n / 10, p + 1);
	*p = "0123456789"[n % 10];
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*p;
	char			*p_temp;

	p = (char *)ft_calloc(ft_numlen(n) + 1, sizeof(char));
	if (!p)
		return (NULL);
	p_temp = p;
	num = (unsigned int)n;
	if (n < 0)
	{
		num = -num;
		p_temp[0] = '-';
		p_temp++;
	}
	ft_itoa_sub(num, p_temp);
	ft_str_swap(p_temp);
	return (p);
}
