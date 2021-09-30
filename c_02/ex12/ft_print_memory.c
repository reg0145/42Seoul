/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:53:43 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/22 01:42:07 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, int len)
{
	int				idx;
	unsigned char	ch;

	idx = 0;
	while (idx < len)
	{
		ch = str[idx];
		if (ch >= 32 && ch < 127)
			write(1, &ch, 1);
		else
			write(1, ".", 1);
		idx++;
	}
}

void	ft_number_hex(unsigned long long nb, char *arr, int size)
{	
	if (size - 1 > 0)
		ft_number_hex(nb / 16, arr, size - 1);
	arr[size - 1] = "0123456789abcdef"[nb % 16];
}

void	ft_char_hex(unsigned char nb, char *arr, int size)
{	
	if (size - 1 > 0)
		ft_number_hex(nb / 16, arr, size - 1);
	arr[size - 1] = "0123456789abcdef"[nb % 16];
}

void	ft_print_xxd(void *addr, unsigned int resize)
{
	char			*str;
	char			value[16];
	unsigned int	idx;

	str = (char *)addr;
	ft_number_hex((unsigned long long)addr, value, 16);
	ft_putstr(value, 16);
	ft_putstr(": ", 2);
	idx = 0;
	while (idx < 16)
	{
		if (idx > resize - 1)
			ft_putstr("  ", 2);
		else
		{
			ft_char_hex((unsigned char)str[idx], value, 2);
			ft_putstr(value, 2);
		}
		if (idx % 2 == 1)
			ft_putstr(" ", 1);
		idx++;
	}
	ft_putstr(str, resize);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*str;
	int		resize;
	int		is_first;

	str = addr;
	resize = addr + size - str;
	is_first = 1;
	while (resize > 0)
	{
		if (is_first)
			is_first = 0;
		else
			write(1, "\n", 1);
		if (resize >= 16)
			ft_print_xxd(str, 16);
		else
			ft_print_xxd(str, resize);
		str += 16;
		resize = addr + size - str;
	}
	return (addr);
}
