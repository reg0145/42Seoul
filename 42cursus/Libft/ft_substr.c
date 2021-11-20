/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:22:45 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/20 16:36:13 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	p_len;
	size_t	i;
	char	*result;

	if (s == NULL)
		return (NULL);
	p_len = ft_strlen(&s[start]);
	result = (char *)ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && i < p_len)
	{
		result[i] = s[start + i];
		i++;
	}
	return (result);
}
