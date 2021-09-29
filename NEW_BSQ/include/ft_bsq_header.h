/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:50:46 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/30 00:44:37 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_HEADER_H
# define FT_BSQ_HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define MAX_VALUE 2100000000

typedef struct s_max
{
	int	val;
	int	x;
	int	y;
}			t_max;

typedef struct s_minfo
{
	int		row;
	int		col;
	char	empty;
	char	full;
	char	block;
	t_max	max;
}			t_minfo;

int		ft_atoi_n(char *str, int n);
int		ft_size_col(char *buf);
int		ft_valid_word(char *str, int col_size, t_minfo *minfo);
int		ft_valid_index(char *str, t_minfo *minfo);
int		ft_strlen(char *str, char ch);
char	*ft_strdup(char *src);
int		ft_check_map_info(char *g_buf, int size, t_minfo *minfo);
int		ft_check_map_layout(char *buf, t_minfo *minfo);
void	ft_set_map(int	***map, char *buf, t_minfo *minfo);
void	ft_set_value(int **map, char *buf, t_minfo *minfo);
void	ft_unset_map(int ***map, t_minfo *minfo);
void	ft_find_square(int **map, t_minfo *minfo);
void	ft_make_square(char *buf, t_minfo *minfo);
void	ft_error(void);
#endif
