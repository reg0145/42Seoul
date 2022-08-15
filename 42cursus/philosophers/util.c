#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>

void	*ft_calloc(size_t num, size_t size)
{
	char	*step;
	size_t	i;
	size_t	total;

	total = num * size;
	step = (char *)malloc(sizeof(char) * total);
	if (step == NULL)
		return (NULL);
	i = 0;
	while (i < total)
		step[i++] = 0;
	return ((void *)step);
}

double	get_passed_time(struct timeval s)
{
	struct timeval	e;

	if (gettimeofday(&e, NULL) == -1)
		return (0);
	return (e.tv_sec - s.tv_sec) + ((double)(e.tv_usec - s.tv_usec) / 1000000);
}

long	uxsleep(double ms)
{
	double			passed;
	double			now;
	struct timeval	s;
	struct timeval	e;

	if (gettimeofday(&s, NULL) == -1)
		return (0);
	passed = (double)ms / 1000;
	now = 0;
	while (now < passed)
	{
		usleep(250);
		gettimeofday(&e, NULL);
		now = (e.tv_sec - s.tv_sec) + ((double)(e.tv_usec - s.tv_usec) / 1000000);
	}
	return (passed);
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
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
	while (*s >= '0' && *s <= '9')
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
