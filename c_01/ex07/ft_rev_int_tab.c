/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:11:01 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/17 20:45:19 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	temp;

	index = 0;
	while (index < size / 2)
	{
		temp = tab[size - index - 1];
		tab[size - index - 1] = tab[index];
		tab[index] = temp;
		index++;
	}
}
