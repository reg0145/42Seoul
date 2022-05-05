/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:26:26 by donghyuk          #+#    #+#             */
/*   Updated: 2022/05/04 16:52:46 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_error(char	*msg)
{
	int	len;

	len = ft_strlen(msg);
	write(1, msg, len);
	exit(1);
}

int	ft_atoi(const char *s)
{
	unsigned long long	result;

	result = 0;
	while (*s)
	{
		result *= 10;
		result += *s - '0';
		s++;
		if (result > 100000)
			return (-1);
	}
	return ((int)(result));
}

char	*ft_itoa(int n)
{
	char	*p;
	int		len;
	int		num;
	int		idx;

	num = n;
	len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
		ft_error("malloc_fail");
	p[len] = '\0';
	idx = 0;
	while (len-- > idx)
	{
		p[len] = "0123456789"[n % 10];
		n /= 10;
	}
	return (p);
}

void	set_sigaction(int sig, void (*f)(int signo, siginfo_t *signinfo, void *unused))
{
	struct sigaction	act;

	act.sa_sigaction = f;
	act.sa_flags = SA_SIGINFO | SA_NODEFER;
	if (sigaction(sig, &act, NULL) == -1)
		ft_error("sigaction_error\n!");
}
