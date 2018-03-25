#include "ft_printf.h"

static long long	ft_printf_d_get(t_printf *pf, char size)
{
	long long	nbr;

	nbr = va_arg(pf->ap, int);
	return (nbr);
}

int					ft_printf_d(t_printf *pf)
{

	return (EXIT_SUCCESS);
}
