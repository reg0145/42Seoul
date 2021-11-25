/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:24:43 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/23 20:46:09 by donghyuk         ###   ########.fr       */
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

static void	ft_itoa_sub(unsigned int n, char *p)
{
	if (n > 9)
		ft_itoa_sub(n / 10, p + 1);
	*p = "0123456789"[n % 10];
}

void	ft_putnbr_fd(int n, int fd)
{
	char			ch[12];
	unsigned int	num;

	ft_memset(ch, 0, 12);
	num = (unsigned int)n;
	if (n < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	ft_itoa_sub(num, ch);
	ft_str_swap(ch);
	ft_putstr_fd(ch, fd);
}
