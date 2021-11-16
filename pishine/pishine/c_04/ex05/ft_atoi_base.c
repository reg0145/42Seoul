/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:08:00 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/22 16:03:34 by donghyuk         ###   ########.fr       */
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

int	ft_is_base(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx] != '\0')
	{
		if (base[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_check_base(char *str)
{
	int				idx;
	unsigned char	clist[256];

	idx = 0;
	while (idx < 256)
		clist[idx++] = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (clist[(unsigned char)str[idx]]++ == 1)
			return (0);
		if (str[idx] == '+' || str[idx] == '-' || str[idx] == ' ')
			return (0);
		idx++;
	}
	if (idx < 2)
		return (0);
	return (idx);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	minus;
	int	result;
	int	base_index;

	len = ft_check_base(base);
	if (len == 0)
		return (0);
	else
	{
		result = 0;
		minus = 1;
		while (ft_is_space(*str))
			str++;
		while (ft_is_operator(*str, &minus))
			str++;
		base_index = ft_is_base(*str, base);
		while (base_index != -1)
		{
			result *= len;
			result += base_index;
			base_index = ft_is_base(*(++str), base);
		}
		return (result * minus);
	}
}
