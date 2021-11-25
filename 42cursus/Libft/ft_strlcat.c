/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:08:05 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/25 17:24:57 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i_d;
	size_t	i_s;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i_d = dst_len;
	i_s = 0;
	if (dst_len > size)
		return (src_len + size);
	while (src[i_s] != '\0' && i_d + 1 < size)
	{
		dst[i_d] = src[i_s];
		i_d++;
		i_s++;
	}
	if (size != 0)
		dst[i_d] = '\0';
	if (size < i_d)
		return (src_len + size);
	else
		return (src_len + dst_len);
}
