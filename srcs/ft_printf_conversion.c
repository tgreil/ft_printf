#include "ft_printf.h"

static size_t	ft_printf_conversion_flags(t_printf *pf, size_t i)
{
	pf->conv.chang = FALSE;
	pf->conv.to_sign = FALSE;
	pf->conv.space_it = FALSE;
	pf->conv.field_fill_side = LEFT;
	pf->conv.field_fill_char = SPACE_CHAR;
	while (pf->str[i] == ZERO_CHAR || pf->str[i] == HASHTAG_CHAR ||
			pf->str[i] == SUB_CHAR || pf->str[i] == ADD_CHAR ||
			pf->str[i] == SPACE_CHAR || pf->str[i] == QUOTE_CHAR)
	{
		if (pf->str[i] == ZERO_CHAR)
			pf->conv.field_fill_char = ZERO_CHAR;
		else if (pf->str[i] == SUB_CHAR)
			pf->conv.field_fill_side = RIGHT;
		else if (pf->str[i] == ADD_CHAR)
			pf->conv.to_sign = TRUE;
		else if (pf->str[i] == SPACE_CHAR)
			pf->conv.space_it = TRUE;
		else
			pf->conv.chang = TRUE;
		i++;
	}
	return (i);
}

static size_t	ft_printf_conversion_field(t_printf *pf, size_t i)
{
	if (pf->str[i] == GET_ATTR_CHAR)
		pf->conv.field_min = va_arg(pf->ap, size_t);
	else
		pf->conv.field_min = ft_little_atoi(pf->str + i);
	if (pf->str[i] == GET_ATTR_CHAR)
		i++;
	else
		while (pf->str[i] >= '0' && pf->str[i] <= '9')
			i++;
	return (i);
}

static size_t	ft_printf_conversion_precision(t_printf *pf, size_t i)
{
	pf->conv.precision = 0;
	if (pf->str[i] == PRECISION_CHAR)
	{
		i++;
		if (pf->str[i] == GET_ATTR_CHAR)
			pf->conv.precision = va_arg(pf->ap, size_t);
		else
			pf->conv.precision = ft_little_atoi(pf->str + i);
		if (pf->str[i] == GET_ATTR_CHAR)
			i++;
		else
			while (pf->str[i] >= '0' && pf->str[i] <= '9')
				i++;
	}
	return (i);
}

static size_t	ft_printf_convesion_size(t_printf *pf, size_t i)
{
	pf->conv.size = 0;
	if (pf->str[i] == H_CHAR)
	{
		pf->conv.size = 1;
		if (pf->str[i + 1] == H_CHAR && ++i)
			pf->conv.size = 2;
	}
	else if (pf->str[i] == J_CHAR)
		pf->conv.size = 3;
	else if (pf->str[i] == Z_CHAR)
		pf->conv.size = 4;
	else if (pf->str[i] == L_CHAR)
	{
		pf->conv.size = 5;
		if (pf->str[i + 1] == L_CHAR && ++i)
			pf->conv.size = 6;
	}
	else if (pf->str[i] == Q_CHAR)
		pf->conv.size = 6;
	else if (pf->str[i] == LL_CHAR)
		pf->conv.size = 7;
	if (pf->conv.size > 0)
		i++;
	return (i);
}

int				ft_printf_conversion(t_printf *pf)
{
	size_t	i;

	i = pf->i + 1;
	while (pf->str[i] == QUOTE_CHAR)
		i++;
	i = ft_printf_conversion_flags(pf, i);
	while (pf->str[i] == QUOTE_CHAR)
		i++;
	i = ft_printf_conversion_field(pf, i);
	while (pf->str[i] == QUOTE_CHAR)
		i++;
	i = ft_printf_conversion_precision(pf, i);
	while (pf->str[i] == QUOTE_CHAR)
		i++;
	i = ft_printf_convesion_size(pf, i);
	while (pf->str[i] == QUOTE_CHAR)
		i++;
	if (ft_printf_conversion_find(pf, pf->str[i]) == EXIT_SUCCESS)
		pf->i = i;
	else
		pf->printed += ft_putchar_fd(pf->str[pf->i], pf->fd);
	return (EXIT_SUCCESS);
}