/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:08:05 by donghyuk          #+#    #+#             */
/*   Updated: 2021/11/17 16:29:50 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)buf1;
	temp2 = (unsigned char *)buf2;
	i = 0;
	while (i < count)
	{
		if (temp1[i] != temp2[i])
			return ((int)(temp1[i] - temp2[i]));
		i++;
	}
	return (0);
}
