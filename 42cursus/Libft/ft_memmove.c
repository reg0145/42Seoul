/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:08:05 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/19 15:07:30 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t count)
{
	unsigned char	*s;
	unsigned char	*d;

	if (src != dst && count)
	{
		s = (unsigned char *)src;
		d = (unsigned char *)dst;
		if (src > dst)
		{
			while (count--)
				*d++ = *s++;
		}
		else
		{
			while (count--)
				*(d + count) = *(s + count);
		}
	}
	return (dst);
}
