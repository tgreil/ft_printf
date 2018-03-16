#include "ft_printf.h"

int		ft_printf_C(t_printf *pf)
{
	char	*to_print;
	char	c;

	c = (char)va_arg(pf->ap, int);
	if (!(to_print = ft_strndup(&c, 1)))
		return (EXIT_ERROR);
	ft_putstr_fill(pf, to_print, ' ', pf->conv.field_fill_side);
	free(to_print);
	return (EXIT_SUCCESS);
}

int		ft_printf_c(t_printf *pf)
{
	char	*to_print;
	char	c;

	c = (char)va_arg(pf->ap, int);
	if (!(to_print = ft_strndup(&c, 1)))
		return (EXIT_ERROR);
	ft_putstr_fill(pf, to_print, ' ', pf->conv.field_fill_side);
	free(to_print);
	return (EXIT_SUCCESS);
}
