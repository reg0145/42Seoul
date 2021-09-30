/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:41:13 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/20 21:21:01 by donghyuk         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i_src;
	int	i_dest;

	i_dest = ft_strlen(dest);
	i_src = 0;
	while (src[i_src] != '\0' && nb-- > 0)
	{
		dest[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	dest[i_dest] = '\0';
	return (dest);
}
