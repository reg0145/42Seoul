/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:07:26 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/05 10:07:26 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_lst
{
	int				fd;
	char			*buf;
	struct s_lst	*next;
}		t_lst;

char	*get_next_line(int fd);
void	*ft_gnl_calloc(size_t num, size_t size);
char	*ft_gnl_strchr(const char *s, char c);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_strnjoin(char const *s1, char const *s2, size_t size);
int		ft_gnl_strlen(const char *s);
#endif
