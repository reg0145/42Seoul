/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:26:16 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/25 13:37:14 by donghyuk         ###   ########.fr       */
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
		}
		else
			s++;
	}
	return (cnt);
}

static void	ft_free_all(char **list)
{
	unsigned int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		list[i] = NULL;
		i++;
	}
}

static void	ft_split_sub(char **result, char const *s, char c)
{
	char	*start;
	size_t	i;

	i = 0;
	while (*s)
	{
		start = (char *)s;
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			result[i] = (char *)ft_calloc((s - start) + 1, sizeof(char));
			if (result[i] == NULL)
				ft_free_all(result);
			ft_strlcpy(result[i++], start, (s - start) + 1);
		}
		if (*s != '\0')
			s++;
	}
	result[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		 return (NULL);
	result = (char **)ft_calloc(ft_getcnt_word(s, c) + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	ft_split_sub(result, s, c);
	return (result);
}
