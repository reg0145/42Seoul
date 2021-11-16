/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:03:44 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/29 13:57:08 by donghyuk         ###   ########.fr       */
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

void	set_zero(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
		str[i++] = '\0';
}

char	*ft_str_swap(char *str)
{
	int		size;
	int		idx;
	char	temp;

	size = 0;
	while (str[size] != '\0')
		size++;
	idx = 0;
	while (idx < size)
	{
		temp = str[size - 1];
		str[size - 1] = str[idx];
		str[idx] = temp;
		idx++;
		size--;
	}
	return (str);
}
