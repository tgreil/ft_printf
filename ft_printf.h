#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

# define OPTION_NB		5
# define EXIT_ERROR		-1
# define EXIT_SUCCESS	0
# define TRUE			1
# define FALSE			0

typedef struct		s_pf_option
{
	char			*s;
	size_t			s_size;
	int				(*f)(void *);
	char			arg;
}					t_pf_option;

int			ft_putchar(char c);
int			ft_is_op(char *s, char *op, int op_size);

int			ft_printf_c(void *data);
int			ft_printf_d(void *data);
int			ft_printf_s(void *data);
int			ft_printf_mod(void *data);

int			ft_printf(char *s, ...);

int			ft_printf_init(t_pf_option *op);

#endif
