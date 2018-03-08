#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

# define EXIT_ERROR			-1
# define EXIT_SUCCESS		0
# define EXIT_S				EXIT_SUCCESS
# define TRUE				1
# define FALSE				0
# define LEFT				22
# define RIGHT				12
# define GET_ATTR_CHAR		'*'
# define CONVERSION_CHAR	'%'
# define COLOR_CHAR			'{'
# define FD_CHAR			'!'
# define FILE_CHAR			'$'
# define DEFAULT_FILL_CHAR	' '

typedef struct				s_pf_nb
{
	void					*data;
}							t_pf_nb;

typedef struct				s_pf_conversion
{
	t_pf_nb					nb;
	char					to_sign;
	size_t					field_min;
	char					field_fill_char;
	char					field_fill_side;
	size_t					precision;
}							t_pf_conversion;

typedef struct				s_printf
{
	int						fd;
	char					is_file;
	t_pf_conversion			conv;
	va_list					ap;
	size_t					i;
	char					*str;
	size_t					printed;
}							t_printf;

int							ft_putchar_fd(int c, int fd);

int							ft_printf_file(t_printf *pf);
int							ft_printf_fd(t_printf *pf);
int							ft_printf_color(t_printf *pf);
int							ft_printf_conversion(t_printf *pf);
int							ft_printf(char *s, ...);

#endif
