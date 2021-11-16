/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:39:34 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/27 10:16:00 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

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

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	idx;

	idx = 0;
	while ((par + idx)->str != 0)
	{
		ft_putstr((par + idx)->str);
		ft_putchar('\n');
		ft_itoa((par + idx)->size);
		ft_putchar('\n');
		ft_putstr((par + idx)->copy);
		ft_putchar('\n');
		idx++;
	}
}
