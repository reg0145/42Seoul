/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:26:24 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/25 14:48:58 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	while (len > i && ft_strchr(set, *(s1 + len - 1)))
		len--;
	result = (char *)ft_calloc(len - i + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, (s1 + i), len - i + 1);
	return (result);
}
