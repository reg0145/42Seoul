/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:26:16 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/22 14:42:06 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getcnt_word(const char *s, char ch)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != ch)
		{
			cnt++;
			while (*s && *s != ch)
				s++;
			if (*s == '\0')
				return (cnt);
		}
		s++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*start;
	size_t	i;

	result = (char **)ft_calloc(ft_getcnt_word(s, c) + 1, sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	while (*s)
	{
		start = (char *)s;
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			result[i] = (char *)ft_calloc((s - start) + 1, sizeof(char));
			ft_strlcpy(result[i++], start, (s - start) + 1);
			if (*s == '\0')
				break ;
		}
		s++;
	}
	result[i] = 0;
	return (result);
}
