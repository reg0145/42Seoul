/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:22:43 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/29 13:57:02 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	idx;

	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == 0)
		return (0);
	idx = 0;
	while (min < max)
	{
		arr[idx] = min;
		min++;
		idx++;
	}
	return (arr);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = ft_range(min, max);
	if (*range == 0)
		return (-1);
	return (max - min);
}
