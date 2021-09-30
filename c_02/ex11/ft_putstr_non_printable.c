/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:08:27 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/20 11:49:34 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

int	ft_char_is_printable(char c)
{
	if ((c < 32 || c > 126))
	{
		return (0);
	}
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	ch;
	int				index;

	index = 0;
	while (str[index] != '\0')
	{
		if (!ft_char_is_printable(str[index]))
		{
			ch = (unsigned char) str[index];
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[ch / 16]);
			ft_putchar("0123456789abcdef"[ch % 16]);
		}
		else
			ft_putchar(str[index]);
		index++;
	}
}
