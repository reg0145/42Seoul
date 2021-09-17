/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:10:08 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/17 21:13:32 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if ((str[idx] < 'A' || str[idx] > 'Z'))
		{
			return (0);
		}
		idx++;
	}
	return (1);
}
