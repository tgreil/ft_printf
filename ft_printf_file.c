#include "ft_printf.h"

int		ft_printf_file_open(t_printf *pf, char *file_name)
{
	int	fd;

	if (!file_name)
		return (EXIT_ERROR);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (EXIT_ERROR);
	pf->fd = fd;
	pf->is_file = TRUE;
	return (EXIT_SUCCESS);
}

int		ft_printf_file(t_printf *pf)
{
	size_t	i;

	i = pf->i + 1;
	while (pf->str[i] && pf->str[i] != FILE_CHAR)
		i++;
	if (pf->str[i])
	{
		if (i - pf->i == 2 && pf->str[pf->i + 1] == GET_ATTR_CHAR &&
			ft_printf_file_open(pf, va_arg(pf->ap, char *)) == EXIT_S)
			pf->i = i;
		else if (ft_printf_file_open(pf, pf->str + pf->i + 1) == EXIT_S)
			pf->i = i;
	}
	if (pf->is_file == FALSE)
	{
		pf->printed += ft_putchar_fd(pf->str[pf->i], pf->fd);
		pf->i += 1;
	}
	return (EXIT_SUCCESS);
}
