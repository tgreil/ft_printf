#include "ft_printf.h"

int		ft_printf_mod(void *data)
{
	data += 1;
	return (ft_putchar('%'));
}

int		ft_printf_c(void *data)
{
	return (ft_putchar((long)data));
}

int		ft_printf_d(void *data)
{
	int		printed;
	long	nb;

	printed = 0;
	nb = (long)(data);
	if ((nb < 0 ? -nb : nb) < 10 && nb != INT_MIN)
	{
		if (nb < 0)
			printed += ft_putchar('-');
		printed += ft_putchar((nb < 0 ? -nb : nb) + '0');
	}
	else
	{
		printed += ft_printf_d((void *)(nb / 10));
		nb = nb % 10;
		printed += ft_putchar((nb < 0 ? -nb : nb) + '0');
	}
	return (printed);
}

int		ft_printf_s(void *data)
{
	int		printed;
	char	*s;
	int		i;

	i = 0;
	printed = 0;
	s = (char *)(data);
	while (s[i])
	{
		printed += ft_putchar(s[i]);
		i++;
	}
	return (printed);
}
