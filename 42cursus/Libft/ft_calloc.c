/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:08:05 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/19 11:38:46 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*temp;
	size_t			i;
	size_t			total;

	total = num * size;
	temp = (unsigned char *)malloc(total);
	i = 0;
	while (i < total)
		temp[i++] = 0;
	return (temp);
}
