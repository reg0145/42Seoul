/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:07:15 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/22 13:25:01 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_itoa(unsigned int nb)
{	
	if (nb > 9)
		ft_itoa(nb / 10);
	ft_putchar("0123456789"[nb % 10]);
}

void	ft_putnbr(int nb)
{
	unsigned int	num;

	num = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	ft_itoa(num);
}
