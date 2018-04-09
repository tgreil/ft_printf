/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:55 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 15:14:27 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_sign_print(t_printf *pf, char is_neg)
{
	if (is_neg || pf->conv.to_sign)
	{
		if (is_neg)
			pf->printed += ft_putchar_fd('-', pf->fd);
		else
			pf->printed += ft_putchar_fd('+', pf->fd);
	}
}

void		ft_printf_precision_print(t_printf *pf)
{
	pf->printed += ft_print_char_xtime('0', pf->conv.precision, pf->fd);
}

void		ft_printf_field_print(t_printf *pf, char s)
{
	if (s == pf->conv.field_fill_side && pf->conv.field_fill_char == ' ')
	{
		pf->printed += ft_print_char_xtime(' ', pf->conv.field_min, pf->fd);
	}
}

long long	ft_printf_type_get(t_printf *pf, char type)
{
	long long	nbr;

	if (type == 1)
		nbr = (short)va_arg(pf->ap, int);
	else if (type == 2)
		nbr = (char)va_arg(pf->ap, int);
	else if (type == 3)
		nbr = va_arg(pf->ap, unsigned int);
	else if (type == 5)
		nbr = va_arg(pf->ap, long);
	else if (type == 6)
		nbr = va_arg(pf->ap, long long);
	else
		nbr = va_arg(pf->ap, int);
	return (nbr);
}
