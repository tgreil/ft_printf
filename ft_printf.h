#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

# define ABS(n)				n < 0 ? -n : n
# define EXIT_ERROR			-1
# define EXIT_SUCCESS		0
# define EXIT_S				EXIT_SUCCESS
# define STD_OUT			1
# define STD_ERROR			2
# define TRUE				1
# define FALSE				0
# define LEFT				22
# define RIGHT				12
# define GET_ATTR_CHAR		'*'
# define G_A_C				GET_ATTR_CHAR
# define CONVERSION_CHAR	'%'
# define COLOR_CHAR			'{'
# define COLOR_CHAR_END		'}'
# define COLOR_SIZE			5
# define FD_CHAR			'!'
# define FILE_CHAR			'$'
# define DEFAULT_FILL_CHAR	' '
# define HASHTAG_CHAR		'#'
# define ZERO_CHAR			'0'
# define SUB_CHAR			'-'
# define ADD_CHAR			'+'
# define SPACE_CHAR			' '
# define PRECISION_CHAR		'.'
# define L_CHAR				'l'
# define LL_CHAR			'L'
# define H_CHAR				'h'
# define Z_CHAR				'z'
# define J_CHAR				'j'
# define Q_CHAR				'q'
# define QUOTE_CHAR			'\''
# define PRINT_NULL			"(null)"

typedef struct				s_pf_nb
{
	void					*data;
}							t_pf_nb;

typedef struct				s_pf_conversion
{
	t_pf_nb					nb;
	char					size;
	char					chang;
	char					to_sign;
	char					space_it;
	size_t					precision;
	size_t					field_min;
	char					field_fill_char;
	char					field_fill_side;
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

size_t						ft_strlen(char *str);
size_t						ft_putstr_fd(char *str, int fd);
int							ft_putchar_fd(int c, int fd);
char						*ft_strndup(char *str, size_t n);
int							ft_little_atoi(char *str);
char						*ft_super_itoa(long long n, char *b, size_t s);

int							ft_printf_a(t_printf *pf, char *b, char o, char p);
int							ft_printf_b(t_printf *pf);
int							ft_printf_c(t_printf *pf);
int							ft_printf_C(t_printf *pf);
int							ft_printf_d(t_printf *pf);


void						ft_printf_conv_sign(char *s,
													t_pf_conversion conv);
size_t						ft_printf_conv_print(char *s,
											t_pf_conversion conv, int fd);
int							ft_printf_conversion_find(t_printf *p, char c);
int							ft_printf_file(t_printf *pf);
int							ft_printf_fd(t_printf *pf);
int							ft_printf_color(t_printf *pf);
int							ft_printf_conversion(t_printf *pf);
int							ft_printf(char *s, ...);

#endif
