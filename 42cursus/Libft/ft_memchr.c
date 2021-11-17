/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:08:05 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/17 16:09:08 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *buf, int c, size_t count)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)buf;
	while (i < count)
	{
		if (temp[i] == (unsigned char) c)
			return (&buf[i]);
		i++;
	}
	return ((void *)0);
}
