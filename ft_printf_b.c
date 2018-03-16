#include "ft_printf.h"

int		ft_printf_b(t_printf *pf)
{
	unsigned char	data;
	unsigned char	i;
	char			i_i;

	i = 0;
	data = (unsigned char)va_arg(pf->ap, int);
	while (i < 8)
	{
		i_i = data >> i & 1;
		pf->printed += ft_putchar_fd(i_i + '0', pf->fd);
		i++;
	}
	return (EXIT_SUCCESS);
}
