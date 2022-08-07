/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:07:24 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/05 10:07:24 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_gnl_calloc(size_t num, size_t size)
{
	char	*step;
	size_t	i;
	size_t	total;

	total = num * size;
	step = (char *)malloc(sizeof(char) * total);
	if (step == NULL)
		return (NULL);
	i = 0;
	while (i < total)
		step[i++] = 0;
	return ((void *)step);
}

char	*ft_gnl_strchr(const char *s, char c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' || *s == c)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;
	size_t	idx;

	if (!s2)
		return (NULL);
	s1_len = ft_gnl_strlen(s1);
	s2_len = ft_gnl_strlen(s2);
	result = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	idx = 0;
	while (s1 && *s1)
	{
		result[idx] = *s1++;
		idx++;
	}
	while (*s2)
	{
		result[idx] = *s2++;
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

char	*ft_gnl_strnjoin(char const *s1, char const *s2, size_t size)
{
	char	*result;
	size_t	idx;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (s1 && *s1 && idx < size)
	{
		result[idx] = *s1++;
		idx++;
	}
	while (*s2 && idx < size)
	{
		result[idx] = *s2++;
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

int	ft_gnl_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
