#include "ft_printf.h"

void	ft_printf_init_add(t_pf_option *op, char *s, int (*f)(void *), int arg)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	op->s = malloc(size + 1);
	size = 0;
	while (s[size])
	{
		op->s[size] = s[size];
		size++;
	}
	op->s[size] = 0;
	op->s_size = size;
	op->f = f;
	op->arg = arg;
}

int		ft_printf_init(t_pf_option *op)
{
	int	i;

	i = 0;
	ft_printf_init_add(op + i++, "%d", &ft_printf_d, 1);
	ft_printf_init_add(op + i++, "%s", &ft_printf_s, 1);
	ft_printf_init_add(op + i++, "%%", &ft_printf_mod, 0);
	ft_printf_init_add(op + i++, "%c", &ft_printf_c, 1);
	ft_printf_init_add(op + i++, "%i", &ft_printf_d, 1);
	return (EXIT_SUCCESS);
}
