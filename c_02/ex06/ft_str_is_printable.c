/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:13:58 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/17 21:15:06 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if ((str[idx] < 32 || str[idx] > 126))
		{
			return (0);
		}
		idx++;
	}
	return (1);
}
