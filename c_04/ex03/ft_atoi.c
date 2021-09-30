/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:07:27 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/22 15:53:49 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_is_operator(char c, int *minus)
{
	if (c == '-')
	{
		*minus *= -1;
		return (1);
	}
	if (c == '+')
		return (1);
	return (0);
}

int	ft_is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	result;
	int	minus;

	minus = 1;
	result = 0;
	while (ft_is_space(*str))
		str++;
	while (ft_is_operator(*str, &minus))
		str++;
	while (ft_is_num(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * minus);
}
