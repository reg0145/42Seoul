/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:57:37 by donghyuk          #+#    #+#             */
/*   Updated: 2021/12/06 21:47:47 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#define HASHMAP_SIZE 100

static t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static t_list   *find_lstfd(t_list **head)
{
	t_list	*lst;
	lst = *head;
    while (lst)
	{
		// fd가 있다.
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}



char	*get_next_line(int	fd)
{
	static t_list	**hash[HASHMAP_SIZE];
	t_list			**head;
	t_list			*node;
	char			buff[BUFFER_SIZE];
	int				size;

	head = hash[fd % HASHMAP_SIZE];
	if (head == NULL)
	{
		head = (t_list *)malloc(sizeof(t_list));
		hash[fd % HASHMAP_SIZE] = head;
		if (head == NULL)
		{
			//freeAll();
			return (NULL);
		}
	}
	//
	node = find_lstfd(head);
	if (node == NULL)
	{
		node = (t_list *)malloc(sizeof(t_list));
		node->fd = fd;
	}
	if (node->rest != NULL)
	{
		char	*temp;

		temp = ft_strchr(node->rest, '\n');
		if (temp == NULL)
			return (NULL);
		return strlcat(temp - node->rest);
		//rest 문자열에 '\n'이 있는지 확인한다.
	}
	//rest 문자열에 '\n'이 있는지 확인한다.
	// rest문자열에 '\n'이 없거나 node가 없다면 read를 한다.
	size = read(fd, buff, BUFFER_SIZE);
	while (size)
	{
		//size가 있다면 lcat을 한다.
		// () 읽은 문자열을 합쳐서 넣는디ㅏ
		index = ft_strchr(node->rest, '\n')

		//rest 문자열에 '\n'이 있는지 확인한다.
		size = read(fd, buff, BUFFER_SIZE);
	}
	if (size == 0)

	// 만약 0이라면 남아있는 데이터를 출력한다.

	return ("1");
}
