/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:08:05 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/19 14:48:45 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char	*d_tmp;
	char	*s_tmp;

	d_tmp = (char *)dest;
	s_tmp = (char *)src;
	while (count--)
		*d_tmp++ = *s_tmp++;
	return (dest);
}
