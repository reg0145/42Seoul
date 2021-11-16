/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:54:05 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/29 14:11:19 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = 0;
	return (dest);
}

int	ft_is_charset(char	ch, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (!ft_is_charset(*str, charset))
		{
			count++;
			while (!ft_is_charset(*str, charset) && *str != '\0')
				str++;
		}
		if (*str == '\0')
			return (count);
		str++;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*start;
	int		count;
	int		i;

	count = ft_count_word(str, charset);
	result = (char **)malloc(sizeof(char *) * count + 1);
	if (!result)
		return (0);
	i = 0;
	while (*str != 0)
	{
		start = str;
		if (!ft_is_charset(*str, charset))
		{
			while (!ft_is_charset(*str, charset) && *str != '\0')
				str++;
			result[i] = (char *)malloc(sizeof(char) * (str - start) + 1);
			result[i] = ft_strncpy(result[i], start, (str - start));
			i++;
		}
		str++;
	}
	result[i] = 0;
	return (result);
}
