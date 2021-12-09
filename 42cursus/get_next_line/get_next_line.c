/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:57:37 by donghyuk          #+#    #+#             */
/*   Updated: 2021/12/08 16:11:25 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#define HASH_SIZE 100

static t_list	*get_node_list(t_list **list, int fd)
{
	t_list	*node;
	t_list	*temp;

	node = *list;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		temp = node;
		node = node->next;
	}
	if (node == NULL)
	{
		node = (t_list *)ft_calloc(1, sizeof(t_list));
		if (node == NULL)
			return (NULL);
		if (*list == NULL)
			*list = node;
		else
			temp->next = node;
		node->fd = fd;
	}
	return (node);
}

static t_list	*get_node_table(t_list **table[], int fd)
{
	int	idx;

	idx = fd % HASH_SIZE;
	if (table[idx] == NULL)
	{
		table[idx] = (t_list **)ft_calloc(1, sizeof(t_list *));
		if (table[idx] == NULL)
			return (NULL);
	}
	return (get_node_list(table[idx], fd));
}

static int	free_all_table(t_list **table[])
{
	int	i;

	if (table == NULL)
		return ;
	i = 0;
	while (i < HASH_SIZE)
	{
		if (table[i] != NULL)
		{
			if ((*table[i])->rest != NULL)
				free((*table[i])->rest);
			free(table[i]);
			table[i] = NULL;
		}
		i++;
	}
	return (NULL);
}

static int	read_fd(t_list *node)
{
	char	buff[BUFFER_SIZE];
	char	*temp;
	int		size;
	int		idx;

	size = read(node->fd, buff, BUFFER_SIZE);
	while (size > 0)
	{
		temp = ft_strjoin(node->rest, buff, size);
		if (temp == NULL)
			return (-1);
		free(node->rest);
		node->rest = temp;
		idx = ft_strchr(temp);
		if (idx)
			return (idx);
		size = read(node->fd, buff, BUFFER_SIZE);
	}
	return (size);
}

char	*get_next_line(int	fd)
{
	static t_list	**table[HASH_SIZE];
	t_list			*node;
	int				idx;
	char			*output;

	node = get_node_table(table, fd);
	if (node == NULL)
		return (free_all_table(table));
	idx = ft_strchr(node->rest);
	if (idx == 0)
		idx = read_fd(node);
	if (idx == -1)
		return (free_all_table(table));
	if (idx == 0)
	{
		output = ft_strjoin(NULL, node->rest, ft_strlen(node->rest));
		free_all_table(table);
		return (output);
	}
	if ()
	{

	}
	return (out_str);
}
