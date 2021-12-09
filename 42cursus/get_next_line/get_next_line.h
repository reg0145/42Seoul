/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:57:53 by donghyuk          #+#    #+#             */
/*   Updated: 2021/12/08 16:12:34 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
typedef struct s_list
{
	int				fd;
	char			*rest;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
char	*get_next_line(int	fd);
char	*ft_strjoin(char const *s1, char const *s2, size_t size);
size_t	ft_strlen(const char *s);
char	*isline(t_list *node);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t num, size_t size);
#endif
