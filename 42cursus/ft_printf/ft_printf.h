#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define FLAG_SPACE 0x0001
# define FLAG_PLUS  0x0002
# define FLAG_MINUS 0x0004
# define FLAG_HASH  0x0008
# define FLAG_ZERO  0x0010

# define TRUE 1

int	ft_printf(const char *format, ...);

#endif
