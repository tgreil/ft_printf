#include "ft_printf.h"

int		ft_putchar_fd(int c, int fd)
{
	return (write(fd, &c, 1) > 0 ? 1 : 0);
}
