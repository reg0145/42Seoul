/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 02:22:50 by donghyuk          #+#    #+#             */
/*   Updated: 2022/05/05 17:04:03 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

t_nlist	g_clients;

void	recv_handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	if (g_clients.front->pid == siginfo->si_pid)
	{
		g_clients.front->data[g_clients.front->cur_size / 8] <<= 1;
		g_clients.front->data[g_clients.front->cur_size++ / 8] |= (1 & signo);
	}
	else
		add_client(&g_clients, siginfo->si_pid);
}

void	listen_handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	if (!g_clients.front || g_clients.front->pid != siginfo->si_pid)
	{
		add_client(&g_clients, siginfo->si_pid);
		return ;
	}
	g_clients.front->tot_size <<= 1;
	g_clients.front->tot_size |= (1 & signo);
	g_clients.front->cur_size++;
}

void	ft_listen(t_nlist *clients)
{
	set_sigaction(SIGUSR1, listen_handler);
	set_sigaction(SIGUSR2, listen_handler);
	while (1)
	{
		if (clients->front != NULL)
		{
			if (kill(clients->front->pid, SIGUSR1))
				ft_error("signal_send_fail");
			break ;
		}
		else
			usleep(100);
	}
}

void	ft_recv(t_nlist *clients)
{
	int	tot_size;

	while (1)
	{
		if (clients->front->cur_size == sizeof(size_t) * 8)
		{
			set_sigaction(SIGUSR1, recv_handler);
			set_sigaction(SIGUSR2, recv_handler);
			clients->front->cur_size = 0;
			clients->front->tot_size *= 8;
			tot_size = clients->front->tot_size;
			clients->front->data = (char *)malloc(sizeof(char) * tot_size + 1);
			if (!clients->front->data)
				ft_error("malloc_fail");
			if (kill(clients->front->pid, SIGUSR1))
				ft_error("signal_send_fail");
			break ;
		}
		else
			usleep(100);
	}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "[server(", 8);
	write(1, pid, ft_strlen(pid));
	write(1, ")] Listening...\n", 17);
	free(pid);
	while (1)
	{
		ft_listen(&g_clients);
		ft_recv(&g_clients);
		ft_print_message(&g_clients);
		usleep(100);
	}
}
