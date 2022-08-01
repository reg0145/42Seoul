/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:26:16 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/15 02:36:32 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getcnt_str(const char *s, char ch)
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

void	ft_free_all(char **list)
{
	unsigned int	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		list[i] = NULL;
		i++;
	}
	free(list);
}

void	*ft_split_sub(char **result, char const *s, char c)
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
			{
				ft_free_all(result);
				return (0);
			}
			ft_strlcpy(result[i++], start, (s - start) + 1);
		}
		else
			s++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	cnt;

	if (s == NULL)
		 return (NULL);
	cnt = ft_getcnt_str(s, c);
	result = (char **)ft_calloc(cnt + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = ft_split_sub(result, s, c);
	return (result);
}
