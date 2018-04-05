/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:03 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/05 15:32:05 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_printf_b_get(t_printf *pf, char size)
{
	long long	nbr;

	if (size == 1)
		nbr = (short)va_arg(pf->ap, int);
	else if (size == 2)
		nbr = (char)va_arg(pf->ap, int);
	else if (size == 5)
		nbr = va_arg(pf->ap, long);
	else if (size == 6)
		nbr = va_arg(pf->ap, long long);
	else
		nbr = va_arg(pf->ap, int);
	return (nbr);
}

int					ft_printf_b(t_printf *pf)
{
	long long	nbr;
	char		*c_nbr;
	int			test;

	nbr = ft_printf_b_get(pf, pf->conv.size);
	if (!(c_nbr = ft_llong_itoa(nbr < 0 ? -nbr : nbr, "01")))
		return (EXIT_ERROR);
	test = pf->conv.field_fill_char;
	if (pf->conv.field_fill_char != ' ')
		ft_printf_sign(pf, (nbr < 0));
	if (pf->conv.precision > ft_strlen(c_nbr))
		pf->conv.field_min += ft_strlen(c_nbr) - pf->conv.precision;
	if (pf->conv.space_it && nbr >= 0 && !pf->conv.to_sign)
		pf->conv.field_min += (pf->conv.field_min ? 0 : 1 + ft_strlen(c_nbr));
	ft_printf_field(pf, c_nbr, (nbr < 0), LEFT);
	if (test == ' ')
		ft_printf_sign(pf, (nbr < 0));
	pf->conv.field_min = pf->conv.precision;
	if ((nbr < 0) || pf->conv.to_sign)
		pf->conv.field_min++;
	pf->conv.field_fill_char = '0';
	ft_printf_field(pf, c_nbr, (nbr < 0), LEFT);
	pf->printed += ft_putstr_fd(c_nbr, pf->fd);
	ft_printf_field(pf, c_nbr, (nbr < 0), RIGHT);
	return (EXIT_SUCCESS);
}
