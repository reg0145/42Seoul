/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:09:19 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/17 22:30:15 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	src_len;

	if (src == 0 || dest == 0)
		return (0);
	src_len = ft_strlen(src);
	idx = 0;
	while (idx < src_len && idx < size - 1)
	{
		dest[idx] = src[idx];
		idx++;
	}
	if (size > 0)
		dest[idx] = '\0';
	return (src_len);
}
