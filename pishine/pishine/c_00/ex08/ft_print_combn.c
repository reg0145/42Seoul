/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:17:25 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/15 07:42:16 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn_recursive(char *p, int index, int len)
{
	if (index == len)
	{
		write(1, p, len);
		if (p[0] != (10 - len + '0'))
			write(1, ", ", 2);
		return ;
	}
	if (index > 0)
		p[index] = p[index - 1] + 1;
	while (p[index] <= '9')
	{
		ft_print_combn_recursive(p, index + 1, len);
		p[index]++;
	}
}

void	ft_print_combn(int n)
{
	char	nums[10];
	char	*p;

	p = nums;
	*p = '0';
	ft_print_combn_recursive(p, 0, n);
}
