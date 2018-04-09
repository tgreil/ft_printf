/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:28:14 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 15:50:47 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_xxx(t_printf *pf, char *base, char *prefix)
{
	long long	nbr;
	char		*c_nbr;
	int			c_nbr_len;

	nbr = ft_printf_type_get(pf, pf->conv.size);
	if (!(c_nbr = ft_llong_itoa(nbr < 0 ? -nbr : nbr, base)))
		return (EXIT_ERROR);
	c_nbr_len = ft_strlen(c_nbr);
	pf->conv.precision -= c_nbr_len;
	if (pf->conv.chang)
		c_nbr_len += ft_strlen(prefix);
	if (pf->conv.to_sign || nbr < 0)
		c_nbr_len++;
	pf->conv.field_min -= c_nbr_len;
	if (pf->conv.precision > 0)
		pf->conv.field_min -= pf->conv.precision;
	ft_printf_field_print(pf, LEFT);
	ft_printf_sign_print(pf, nbr < 0);
	if (pf->conv.chang)
		pf->printed += ft_putstr_fd(prefix, pf->fd);
	ft_printf_precision_print(pf);
	pf->printed += ft_putstr_fd(c_nbr, pf->fd);
	ft_printf_field_print(pf, RIGHT);
	return (EXIT_SUCCESS);
}

int			ft_printf_xx(t_printf *pf)
{
	return (ft_printf_xxx(pf, "0123456789ABCDEF", "0X"));
}

int			ft_printf_x(t_printf *pf)
{
	return (ft_printf_xxx(pf, "0123456789abcdef", "0x"));
}
