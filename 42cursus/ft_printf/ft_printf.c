/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:19:57 by donghyuk          #+#    #+#             */
/*   Updated: 2021/12/16 23:25:49 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchrnul(const char *s, int c)
{
	while (*s != '\0' || *s == c)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

static int	ft_vsprintf(const char *f, va_list arg)
{
	unsigned char	flag;
	int				done;

	done = 0;
	flag = 0;
	while (*f)
	{
		// %를 찾는 함수를 만들 것인가?
		if (*f++ == '%')
		{
			//ft_parse_flag(&f, &flag);
			//ft_parse_width(&f, flag, arg);
			//ft_parse_precision(&f, flag, arg);
			done += ft_parse_type(&f, flag, arg);
		}
		//문자열을 출력할 것인가?
	}
	return (done);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, format);
	done = ft_vsprintf(format, arg);
	va_end(arg);
	return (done);
}
