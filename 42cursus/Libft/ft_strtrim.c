/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:26:24 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/20 16:32:53 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*p;
	size_t	size;

	start = ft_strchr(s1, *set);
	if (!start)
		start = (char *)s1;
	end = ft_strrchr(s1, *set);
	if (!end)
		end = (char *)s1 + ft_strlen(s1);
	size = end - start;
	p = (char *)ft_calloc(sizeof(char), size);
	ft_strlcpy(p, start, size);
	return (p);
}
