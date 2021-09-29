/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:44:06 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/30 01:32:30 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq_header.h"

int	ft_valid_index(char *str, t_minfo *minfo)
{
	int		i;

	i = 0;
	if (str[i] == str[i + 1] || str[i] == str[i + 2]
		|| str[i + 1] == str[i + 2])
		return (0);
	while (i < 3)
	{
		if (!(32 <= str[i] && str[i] <= 126))
			return (0);
		i++;
	}
	minfo->empty = str[0];
	minfo->block = str[1];
	minfo->full = str[2];
	return (1);
}

int	ft_valid_word(char *str, int col_size, t_minfo *minfo)
{
	int	i;

	i = 0;
	while (i < col_size - 1)
	{
		if (str[i] == '\n')
			return (0);
		if (!(str[i] == minfo->empty || str[i] == minfo->block))
			return (0);
		i++;
	}
	if (str[i] != '\n')
		return (0);
	return (1);
}

int	ft_size_col(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	return (i);
}

int	ft_check_map_info(char *buf, int size, t_minfo *minfo)
{
	int		row_size;

	row_size = ft_atoi_n(buf, size);
	if (row_size == 0)
		return (0);
	if (!ft_valid_index(buf + size - 3, minfo))
		return (0);
	minfo->row = row_size;
	return (1);
}

int	ft_check_map_layout(char *buf, t_minfo *minfo)
{
	int		size;
	int		col_size;
	int		row;

	row = 0;
	col_size = ft_size_col(buf) + 1;
	if (col_size == 1)
		return (0);
	size = ft_strlen(buf, '\n');
	while (size > 1)
	{
		if (size != col_size || !ft_valid_word(buf, col_size, minfo))
			return (0);
		buf = buf + col_size;
		row++;
		size = ft_strlen(buf, '\n');
	}
	if (*buf != '\0')
		return (0);
	if (row != minfo->row || buf[col_size] != '\0')
		return (0);
	minfo->col = col_size;
	return (1);
}
