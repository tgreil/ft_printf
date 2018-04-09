/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:52:09 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 18:13:25 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_oo(t_printf *pf)
{
	ft_printf_o(pf);
	return (EXIT_SUCCESS);
}

int			ft_printf_o(t_printf *pf)
{
	long long	nbr;
	char		*c_nbr;


	nbr = ft_printf_type_get(pf, pf->conv.size, 0);
	if (!(c_nbr = ft_llong_itoa(nbr < 0 ? -nbr : nbr, "01234567")))
		return (EXIT_ERROR);
	ft_printf_field_calc(pf, nbr, c_nbr, NULL);
	if (pf->conv.chang)
	{
		pf->conv.precision++;
		if (pf->conv.precision <= 0)
			pf->conv.precision = 1;
		pf->conv.field_min--;
	}
	ft_printf_field_print(pf, LEFT);
	ft_printf_sign_print(pf, nbr < 0);
	ft_printf_precision_print(pf);
	if (nbr || !pf->conv.to_precis || !pf->conv.precision)
		pf->printed += ft_putstr_fd(c_nbr, pf->fd);
	else if (pf->conv.field_min > 0)
		pf->printed += ft_putstr_fd(" ", pf->fd);
	ft_printf_field_print(pf, RIGHT);
	free(c_nbr);
	return (EXIT_SUCCESS);
}
