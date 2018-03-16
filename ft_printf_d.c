#include "ft_printf.h"

int		ft_printf_d(t_printf *pf)
{
	long long	nbr;
	char		*to_print;

	if (pf->conv.size == 6)
		nbr = va_arg(pf->ap, long long);
	else if (pf->conv.size == 5)
		nbr = va_arg(pf->ap, long);
	else if (pf->conv.size == 4)
		nbr = va_arg(pf->ap, size_t);
	else if (pf->conv.size == 1)
		nbr = (char)va_arg(pf->ap, int);
	else if (pf->conv.size == 2)
		nbr = (short int)va_arg(pf->ap, int);
	else
		nbr = va_arg(pf->ap, int);
	if (!(to_print = ft_super_itoa(nbr, "0123456789", pf->conv.precision + 2)))
		return (EXIT_ERROR);
	ft_printf_conv_sign(to_print, pf->conv);
	pf->printed += ft_printf_conv_print(to_print, pf->conv, pf->fd);
	free(to_print);
	return (EXIT_SUCCESS);
}
