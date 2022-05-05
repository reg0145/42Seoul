/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:08:05 by donghyuk          #+#    #+#             */
/*   Updated: 2022/03/08 01:18:09 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*temp;
	size_t	i;
	size_t	total;

	total = num * size;
	temp = (char *)malloc(sizeof(char) * total);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < total)
		temp[i++] = 0;
	return ((void *)temp);
}
