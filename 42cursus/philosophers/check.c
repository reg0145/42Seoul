#include <unistd.h>

static int	ft_isdigit(char	c)
{
	return (c >= '0' && c <= '9');
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	check_arg(char	*arg)
{
	int	len;
	int	sign_cnt;

	len = ft_strlen(arg);
	if (!len)
		return (1);
	while (--len >= 0)
	{
		if (!ft_isdigit(arg[len]))
			return (1);
		else
			break ;
	}
	sign_cnt = 0;
	while (--len >= 0)
	{
		if (sign_cnt > 0)
			return (1);
		if (ft_isdigit(arg[len]))
			continue;
		if (arg[len] == '-' || arg[len] == '+')
			sign_cnt++;
		else
			return (1);
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (1);
	i = 0;
	while (++i < ac)
		if (check_arg(av[i]))
			return (1);
	return 0;
}
