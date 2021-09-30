/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:15:11 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/15 07:41:42 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	nums[12];
	char	*p;

	p = nums;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		ft_putchar('0');
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb > 0)
	{
		*(p++) = nb % 10 + '0';
		nb /= 10;
	}
	while (--p >= nums)
		ft_putchar(*p);
}
