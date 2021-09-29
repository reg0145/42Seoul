/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:57:32 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/30 00:44:30 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq_header.h"
#include "../include/util.h"

static int		**g_map;
static t_minfo	g_minfo;
static char		*g_buf;

int	ft_read_input(void)
{
	int		size;
	int		i;

	i = 0;
	size = read(0, &g_buf[i], 1);
	while (size)
	{
		if (i == MAX_VALUE)
			return (0);
		if (size == -1)
			return (1);
		i++;
		size = read(0, &g_buf[i], 1);
	}
	return (1);
}

int	ft_read_file(char *f_name)
{
	int	fd;
	int	size;
	int	i;

	i = 0;
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!read(fd, g_buf, MAX_VALUE))
		return (0);
	size = ft_strlen(g_buf, '\n');
	if (size < 4)
		return (0);
	if (!ft_check_map_info(g_buf, size - 1, &g_minfo))
		return (0);
	if (!ft_check_map_layout(g_buf + size, &g_minfo))
		return (0);
	close(fd);
	ft_set_map(&g_map, g_buf + size, &g_minfo);
	write(1, g_buf + size, g_minfo.row * g_minfo.col);
	while (i < g_minfo.row * g_minfo.col)
		g_buf[i++] = 0;
	return (1);
}

int	ft_read_stdio(void)
{
	int	size;

	if (!ft_read_input())
		return (0);
	size = ft_strlen(g_buf, '\n');
	if (!ft_check_map_info(g_buf, size - 1, &g_minfo)
		||!ft_check_map_layout(g_buf + size, &g_minfo))
		return (0);
	ft_set_map(&g_map, g_buf + size, &g_minfo);
	write(1, g_buf + size, g_minfo.row * g_minfo.col);
	g_minfo.row = 0;
	return (1);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		g_buf = (char *)malloc(sizeof(char) * MAX_VALUE);
		if (!g_buf)
			return (0);
		if (!ft_read_stdio())
			ft_error();
		free(g_buf);
	}
	while (i < argc)
	{
		g_buf = (char *)malloc(sizeof(char) * MAX_VALUE);
		if (!g_buf)
			return (0);
		if (!ft_read_file(argv[i]))
			ft_error();
		free(g_buf);
		i++;
		if (i < argc)
			write(1, "\n", 1);
	}
	return (0);
}
