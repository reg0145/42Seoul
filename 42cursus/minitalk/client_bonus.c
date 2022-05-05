/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 02:30:54 by donghyuk          #+#    #+#             */
/*   Updated: 2022/05/05 17:05:40 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	g_signal;

int	ft_check_param(int argc, char *argv[])
{
	int		pid;
	int		idx;

	if (argc != 3)
		ft_error("Please check parameters.: ./client [server_pid] [message]");
	idx = -1;
	while (argv[1][++idx])
		if (!(argv[1][idx] >= '0' && argv[1][idx] <= '9'))
			ft_error("Please check server pid");
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		ft_error("Please check server pid");
	return (pid);
}

void	ft_send_message(int pid, char *str)
{
	int	bit;

	while (*str)
	{
		bit = 8;
		while (--bit >= 0)
		{
			if (kill(pid, SIGUSR1 + (1 & (*str >> bit))))
				ft_error("signal_send_fail");
			usleep(100);
		}
		str++;
	}
	bit = 8;
	while (--bit >= 0)
	{
		if (kill(pid, SIGUSR1))
			ft_error("signal_send_fail");
		usleep(100);
	}
}

void	ft_send_message_size(int pid, char *str)
{
	int		bit;
	size_t	size;

	size = ft_strlen(str) + 1;
	bit = sizeof(size_t) * 8;
	while (--bit >= 0)
	{
		if (kill(pid, SIGUSR1 + (1 & (size >> bit))))
			ft_error("signal_send_fail");
		usleep(300);
	}
}

void	sigusr1_handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)signo;
	(void)siginfo;
	(void)unused;
	if (g_signal == STANDBY)
	{
		write(1, "connected..\n", 13);
		g_signal = CONNECTED;
	}
	else if (g_signal == CONNECTED)
	{
		write(1, "server received the message size..\n", 36);
		g_signal = RECV_MSG_SIZE;
	}
	else if (g_signal == RECV_MSG_SIZE)
	{
		write(1, "Successfully send a message!!", 30);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;

	pid = ft_check_param(argc, argv);
	set_sigaction(SIGUSR1, sigusr1_handler);
	if (kill(pid, SIGUSR1))
		ft_error("signal_send_fail");
	while (g_signal != CONNECTED)
		usleep(100);
	ft_send_message_size(pid, argv[2]);
	while (g_signal != RECV_MSG_SIZE)
		usleep(100);
	ft_send_message(pid, argv[2]);
	while (1)
		pause();
}
