/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:32:41 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/20 21:29:41 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	idx_d;
	unsigned int	idx_s;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	idx_d = dst_len;
	idx_s = 0;
	while (src[idx_s] != '\0' && idx_d + 1 < size)
	{
		dest[idx_d] = src[idx_s];
		idx_d++;
		idx_s++;
	}
	dest[idx_d] = '\0';
	if (size < idx_d)
		return (src_len + size);
	else
		return (src_len + dst_len);
}
