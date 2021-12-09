/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:57:50 by donghyuk          #+#    #+#             */
/*   Updated: 2021/12/08 16:04:24 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] == c)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t size)
{
	char	*result;
	char	*step;
	size_t	idx;

	if (s1 == NULL)
		result = (char *)malloc(sizeof(char) * (size + 1));
	else 
		result = (char *)malloc(sizeof(char) * (size + 1 + ft_strlen(s1)));
	if (result == NULL)
			return (NULL);
	step = result;
	idx = 0;
	while (s1 && *s1 && idx < size)
		*step++ = *s1++;
	while (*s2 && idx < size)
		*step++ = *s2++;
	*step = '\0';
	return (result);
}

char	*get_a_line(t_list *node, int idx)
{
	char	*result;
	char	*temp;

	result = ft_strjoin(NULL, node->rest, idx + 1);
	if (result)
		return (NULL);
	temp = &(node->rest)[idx + 1];
	temp = ft_strjoin(NULL, temp, ft_strlen(temp));
	if (temp)
		return (NULL);
	free(node->rest);
	node->rest = temp;
	return (result);
}

void	*ft_calloc(size_t num, size_t size)
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
