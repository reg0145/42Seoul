/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:24:46 by donghyuk          #+#    #+#             */
/*   Updated: 2022/05/05 14:52:36 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	add_client(t_nlist *list, int pid)
{
	t_client	*tmp;

	tmp = (t_client *)malloc(sizeof(t_client));
	if (tmp == NULL)
		ft_error("malloc_error");
	tmp->pid = pid;
	tmp->next = NULL;
	tmp->cur_size = 0;
	tmp->tot_size = 0;
	if (list->front == NULL)
	{
		list->front = tmp;
		list->rear = tmp;
	}
	else
	{
		list->rear->next = tmp;
		list->rear = tmp;
	}
}

void	remove_client(t_nlist *list)
{
	t_client	*tmp;

	tmp = list->front;
	if (list->front == list->rear)
	{
		list->front = NULL;
		list->rear = NULL;
	}
	else
		list->front = list->front->next;
	free(tmp->data);
	free(tmp);
}

void	ft_print_message(t_nlist *clients)
{
	while (1)
	{
		if (clients->front->tot_size == clients->front->cur_size)
		{
			write(1, clients->front->data, clients->front->tot_size / 8);
			write(1, "\n", 1);
			kill(clients->front->pid, SIGUSR1);
			remove_client(clients);
			break ;
		}
		else
			usleep(100);
	}
}
