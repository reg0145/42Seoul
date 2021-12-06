/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:57:37 by donghyuk          #+#    #+#             */
/*   Updated: 2021/12/07 01:07:54 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#define HASH_SIZE 100

static t_list	*get_lst_node(t_list **head, int fd)
{
	t_list	*lst;

	lst = *head;
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst->next;
	}
	if (lst == NULL)
	{
		lst = (t_list *)malloc(sizeof(t_list));
		if (lst == NULL)
		{
			//freeAll();
			return (NULL);
		}
		ft_lstadd_back(head, lst);
	}
	return (lst);
}

static t_list	**get_lst_plist(t_list **table)
{
	if (table == NULL)
	{
		table = (t_list **)malloc(sizeof(t_list *));
		if (table == NULL)
		{
			//freeAll();
			return (NULL);
		}
	}
	return (table);
}

static char	*get_output_read(t_list *node)
{
	char	buff[BUFFER_SIZE + 1];
	char	*out_str;
	int		size;

	size = read(node->fd, buff, BUFFER_SIZE);
	while (size)
	{
		out_str = ft_strchr(buff, "\n\0");
		if (out_str != NULL)
		{
			if (node->rest != NULL)
			{
				out_str =
			}
			return (out_str);
		}
		size = read(node->fd, buff, BUFFER_SIZE);
	}
	return (NULL);
}

char	*get_next_line(int	fd)
{
	static t_list	**table[HASH_SIZE];
	t_list			**plist;
	t_list			*node;
	char			*out_str;

	plist = get_plist_table(table[fd % HASH_SIZE]);
	if (plist == NULL)
		return (NULL);
	node = get_node_plist(plist, fd);
	if (node == NULL)
		return (NULL);
	out_str = find_newline(node->rest);
	if (out_str == NULL)
		out_str = get_output_read(node);
	return (out_str);
}
