/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:26:16 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/20 16:28:07 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getcnt_word(const char *str, char ch)
{
	size_t	cnt;

	cnt = 1;
	if (ch == '\0')
		return (2);
	while (*str != '\0')
	{
		if (*str == ch)
			cnt++;
		str++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*start;
	size_t	i;

	result = (char **)ft_calloc(sizeof(char *), ft_getcnt_word(s, c));
	if (!result)
		return (0);
	i = 0;
	start = (char *)s;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != c && *s != '\0')
				s++;
			result[i] = (char *)ft_calloc(sizeof(char *), (s - start) + 1);
			ft_strlcpy(result[i], (char *)start, (s - start) + 1);
			start = (char *)s;
			i++;
		}
		s++;
	}
	result[i] = 0;
	return (result);
}
