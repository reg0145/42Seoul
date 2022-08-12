/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:07:20 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/05 10:07:21 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_max_list(int *lst, int len)
{
	int	i;
	int	max;

	i = -1;
	max = INT_MIN;
	while (++i < len)
		if (max < lst[i])
			max = lst[i];
	return (max);
}
