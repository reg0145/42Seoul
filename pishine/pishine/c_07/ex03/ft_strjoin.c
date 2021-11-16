/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:51:13 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/29 17:39:02 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strcat(char *dest, char *src)
{
	int	idx_d;
	int	idx_s;

	idx_d = ft_strlen(dest);
	idx_s = 0;
	while (src[idx_s] != '\0')
	{
		dest[idx_d] = src[idx_s];
		idx_d++;
		idx_s++;
	}
	dest[idx_d] = '\0';
	return (dest);
}

char	*ft_strjoin_sub(int size, char **strs, char *sep, char *temp)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(temp, strs[i]);
		if (i < size - 1)
			ft_strcat(temp, sep);
		i++;
	}
	return (temp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*temp;
	int		strs_len;
	int		sep_len;
	int		i;

	if (size < 1)
		return ((char *)malloc(sizeof(char)));
	i = 0;
	strs_len = 0;
	while (i < size)
	{
		strs_len += ft_strlen(strs[i]);
		i++;
	}
	sep_len = ft_strlen(sep);
	temp = (char *)malloc(sizeof(char) * (strs_len + sep_len * (size - 1)) + 1);
	if (!temp)
		return (0);
	temp[0] = '\0';
	temp = ft_strjoin_sub(size, strs, sep, temp);
	return (temp);
}
