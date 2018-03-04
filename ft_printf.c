#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	t_pf_option	op[OPTION_NB];
	size_t		printed;
	va_list		ap;
	size_t		i;
	size_t		i_op;
	void		*data;

	i = 0;
	printed = 0;
	va_start(ap, str);
	ft_printf_init(op);
	while (str[i])
	{
		i_op = 0;
		while (i_op < OPTION_NB &&
						ft_is_op(str + i, op[i_op].s, op[i_op].s_size) == FALSE)
			i_op++;
		if (i_op == OPTION_NB)
			printed += ft_putchar(str[i]);
		else
		{
			i += op[i_op].s_size - 1;
			if (op[i_op].arg)
				data = va_arg(ap, void *);
			printed += op[i_op].f(data);
		}
		i++;
	}
	return (printed);
}
