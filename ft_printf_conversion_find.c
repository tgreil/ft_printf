#include "ft_printf.h"

int		ft_printf_conversion_find(t_printf *pf, char conv_c)
{
	if (conv_c == 'A')
		return (ft_printf_a(pf, "0123456789ABCDEF", 'o', 'p'));
	else if (conv_c == 'a')
		return (ft_printf_a(pf, "0123456789abcdef", 'O', 'P'));
	else if (conv_c == 'b')
		return (ft_printf_b(pf));
	else if (conv_c == 'c')
		return (ft_printf_c(pf));
	else if (conv_c == 'C')
		return (ft_printf_C(pf));
	else if (conv_c == 'd')
		return (ft_printf_d(pf));
	return (EXIT_ERROR);
}
