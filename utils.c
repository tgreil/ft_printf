#include "ft_printf.h"

int			ft_is_op(char *s, char *op, int op_size)
{
	int	i;

	i = 0;
	while (i < op_size)
	{
		if (s[i] != op[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
