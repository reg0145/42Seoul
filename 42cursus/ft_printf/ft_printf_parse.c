#include "ft_printf.h"
#include "./libft/libft.h"

void	ft_parse_flag(char **f, unsigned char *flag)
{
	register char	c;

	while (TRUE)
	{
		c = *f;
		if (c == '-')
			*flag = (*flag | FLAG_MINUS) & ~FLAG_ZERO;
		else if (c == '+')
			*flag |= FLAG_PLUS;
		else if (c == '#')
			*flag |= FLAG_HASH;
		else if (c == '0')
			if ((*flag & FLAG_MINUS) == 0)
				*flag |= FLAG_ZERO;
		else if (c == ' ')
			*flag |= FLAG_SPACE;
		else
			break ;
		*f++;
	}
}

void	ft_parse_width(char **f, unsigned char *flag, va_list arg)
{
	int	result;

	if (ft_isdigit(**f))
	{
		result = read_int(*f);
	}
}
void	ft_parse_precision(char **f, va_list arg)
{

}

int	ft_parse_type(char **f, va_list arg)
{
	register char	c;
	int				done;

	c = **f;
	if (c == 'c')
		done += ;
	else if (c == 's')
		done += ;
	else if (c == 'p')
		done += ;
	else if (c == 'd')
		done += ;
	else if (c == 'i')
		done += ;
	else if (c == 'u')
		done += ;
	else if (c == 'x')
		done += ;
	else if (c == 'X')
		done += ;
	else if (c == '%')
		done += ;
	return (done);
}
