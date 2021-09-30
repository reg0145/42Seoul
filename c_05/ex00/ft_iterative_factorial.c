/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:28:02 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/25 12:51:37 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	result = 1;
	while (nb > 0)
		result *= nb--;
	return (result);
}
