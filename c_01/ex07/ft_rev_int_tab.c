/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:11:01 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/18 09:20:58 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	idx;
	int	temp;

	idx = 0;
	while (idx < size / 2)
	{
		temp = tab[size - idx - 1];
		tab[size - idx - 1] = tab[idx];
		tab[idx] = temp;
		idx++;
	}
}
