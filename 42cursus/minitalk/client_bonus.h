/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:33:26 by donghyuk          #+#    #+#             */
/*   Updated: 2022/05/05 17:14:44 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define STANDBY 0
# define CONNECTED 1
# define RECV_MSG_SIZE 2

size_t	ft_strlen(const char *s);
void	ft_error(char	*msg);
int		ft_atoi(const char *s);
void	set_sigaction(int sig, void (*f)(int s, siginfo_t *sinfo, void *unuse));

#endif
