/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:52:09 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 15:51:12 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_oo(t_printf *pf)
{
	pf += 1;
	return (EXIT_SUCCESS);
}

int			ft_printf_o(t_printf *pf)
{
	long long	nbr;
	char		*c_nbr;
	int			c_nbr_len;

	nbr = ft_printf_type_get(pf, pf->conv.size);
	if (!(c_nbr = ft_llong_itoa(nbr < 0 ? -nbr : nbr, "0123456789")))
		return (EXIT_ERROR);
	c_nbr_len = ft_strlen(c_nbr);
	pf->conv.precision -= c_nbr_len;
	if (pf->conv.to_sign || nbr < 0)
		c_nbr_len++;
	pf->conv.field_min -= c_nbr_len;
	if (pf->conv.precision > 0)
		pf->conv.field_min -= pf->conv.precision;
	ft_printf_field_print(pf, LEFT);
	ft_printf_sign_print(pf, nbr < 0);
	ft_printf_precision_print(pf);
	pf->printed += ft_putstr_fd(c_nbr, pf->fd);
	ft_printf_field_print(pf, RIGHT);
	return (EXIT_SUCCESS);
}
