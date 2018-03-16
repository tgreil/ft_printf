#include "ft_printf.h"

int	ft_printf_a(t_printf *pf, char *base, char o, char p)
{
	double	nb;

	nb = va_arg(pf->ap, double);
	nb += 1;
	base[0] = o;
	base[1] = p;
	ft_putstr_fd(base, pf->fd);
	return (EXIT_SUCCESS);
}
