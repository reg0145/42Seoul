#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	check_arg(char	*arg)
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

int	ft_atoi(const char *s)
{
	unsigned long long	result;
	int					sign;

	sign = 1;
	result = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		result *= 10;
		result += *s - '0';
		s++;
	}
	if (result > LLONG_MAX && sign == 1)
		return (-1);
	else if (result > (LLONG_MAX + 1LLU) && sign == -1)
		return (0);
	return ((int)(sign * result));
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

int main(int ac, char **av)
{

	if (check_args(ac, av))
	{
		printf("Error");
		return (0);
	}
	if (parse(ac, av))
	{
		printf("Error");
		return (0);
	}
	printf("%d", ft_atoi(av[1]));
	return (1);
}
