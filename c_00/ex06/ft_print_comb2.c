/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:09:36 by colin             #+#    #+#             */
/*   Updated: 2021/09/13 23:57:17 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_nums(int num_a, int num_b)
{
	putchar(num_a / 10) + '0');
	putchar(num_a % 10) + '0');
	putchar(' ');
	putchar(num_b / 10) + '0');
	putchar(num_b % 10) + '0');
}

void	ft_print_comb2(void)
{
	int	num_a;
	int	num_b;

	num_a = 0;
	while (num_a <= 99)
	{
		num_b = num_a + 1;
		while (num_b <= 99)
		{
			ft_print_nums(num_a, num_b);
			if (!(num_a == 98 && num_b == 99))
			{
				write(1, ", ", 2);
			}
			num_b++;
		}
		num_a++;
	}	
}
