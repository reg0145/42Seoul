/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:43:34 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/22 15:40:29 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check_base(char *str)
{
	int				idx;
	unsigned char	clist[256];

	idx = 0;
	while (idx < 256)
		clist[idx++] = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (clist[(unsigned char)str[idx]]++ == 1)
			return (0);
		if (str[idx] == '+' || str[idx] == '-')
			return (0);
		idx++;
	}
	if (idx < 2)
		return (0);
	return (idx);
}

void	ft_itoa(unsigned int nb, char *base, unsigned int len)
{	
	if (nb > len - 1)
		ft_itoa(nb / len, base, len);
	ft_putchar(base[nb % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	num;
	int				len;

	len = ft_check_base(base);
	if (len == 0)
		return ;
	else
	{
		num = nbr;
		if (nbr < 0)
		{
			write(1, "-", 1);
			num = -num;
		}
		ft_itoa(num, base, len);
	}
}
