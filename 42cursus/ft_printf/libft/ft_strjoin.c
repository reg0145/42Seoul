/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:26:35 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/25 11:16:14 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*p;
	char	*p_temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!p)
		return (NULL);
	p_temp = p;
	while (*s1)
		*p_temp++ = *s1++;
	while (*s2)
		*p_temp++ = *s2++;
	*p_temp = '\0';
	return (p);
}
