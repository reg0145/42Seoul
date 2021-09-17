/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:53:43 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/18 01:06:08 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int len)
{
	write(1, str, len);
}

void	*ft_number_hex(unsigned int nb, char *arr, int size)
{	
	if (size - 1 > 0)
		ft_number_hex(nb / 16, arr, size - 1);
	arr[size - 1] = &"0123456789abcdef"[nb % 16];
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*str;
	char	value[16];
	int		idx;

	str = (char *)addr;
	while (str < (char *)addr + size)
	{
		ft_number_hex((unsigned int)addr, value, 16);
		ft_putstr(value, 16);
		ft_putstr(": ", 2);
		while (idx < 32)
		{
			if ((char *)addr + size )
			ft_number_hex((char *)addr + idx, value, 2);
			ft_putchar(str[1]);
			ft_putchar(str[0]);
			if (idx % 2 == 1)
				ft_putchar(' ');
			idx++;
		}
		ft_putstr(str, 16);
		ft_putchar('\n');
		str += 16;
	}
}
