/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:52:05 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/29 13:56:59 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_space(char c);
int		ft_is_operator(char c, int *minus);
int		ft_is_base(char c, char *base);
void	set_zero(char *str, int len);
char	*ft_str_swap(char *str);

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
		if (str[idx] == '+' || str[idx] == '-' || ft_is_space(str[idx]))
			return (0);
		idx++;
	}
	if (idx < 2)
		return (0);
	return (idx);
}

void	ft_itoa(unsigned int nb, char *str, char *base, unsigned int len)
{	
	if (nb > len - 1)
		ft_itoa(nb / len, str + 1, base, len);
	*str = base[nb % len];
}

void	ft_itoa_base(int num, char *result, char *base_to, int len_to)
{
	unsigned int	u_num;
	int				minus_index;

	minus_index = 0;
	u_num = num;
	if (num < 0)
	{
		result[0] = '-';
		u_num = -u_num;
		minus_index = 1;
	}
	ft_itoa(u_num, result + minus_index, base_to, len_to);
	ft_str_swap(result + minus_index);
}

int	ft_atoi_base(char *str, char *base, int len)
{
	int	result;
	int	base_index;
	int	minus;

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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len_from;
	int		len_to;
	int		num;
	char	*result;

	len_from = ft_check_base(base_from);
	len_to = ft_check_base(base_to);
	result = (char *)malloc(sizeof(char) * 34);
	if (!len_from || !len_to || !result)
		return (0);
	set_zero(result, 34);
	num = ft_atoi_base(nbr, base_from, len_from);
	ft_itoa_base(num, result, base_to, len_to);
	return (result);
}
