/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:33:41 by donghyuk          #+#    #+#             */
/*   Updated: 2022/05/05 14:52:37 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_client
{
	int				pid;
	size_t			tot_size;
	size_t			cur_size;
	char			*data;
	struct s_client	*next;
}	t_client;

typedef struct s_nlist
{
	int			status;
	t_client	*front;
	t_client	*rear;
}	t_nlist;

void	add_client(t_nlist *list, int pid);
void	remove_client(t_nlist *list);
void	set_sigaction(int sig, void (*f)(int s, siginfo_t *sinfo, void *unuse));
void	ft_print_message(t_nlist *clients);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
void	ft_error(char *s);

#endif
