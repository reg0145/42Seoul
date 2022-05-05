#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# define STANDBY 0
# define CONNECTED 1
# define RECV_MSG_SIZE 2

size_t	ft_strlen(const char *s);
void	ft_error(char	*msg);
int		ft_atoi(const char *s);
void	set_sigaction(int sig, void (*f)(int signo, siginfo_t *signinfo, void *unused));

#endif
