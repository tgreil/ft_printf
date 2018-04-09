/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:28:14 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 19:21:13 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_xxx(t_printf *pf, char *base, char *prefix)
{
	unsigned long long	nbr;
	char		*c_nbr;

	nbr = ft_printf_type_get(pf, pf->conv.size, 1);
	if (!(c_nbr = ft_llong_itoa(nbr, base)))
		return (EXIT_ERROR);
	ft_printf_field_calc(pf, nbr, c_nbr, nbr ? prefix : NULL);
	ft_printf_field_print(pf, LEFT);
	ft_printf_sign_print(pf, 0);
	if (pf->conv.chang && nbr)
		pf->printed += ft_putstr_fd(prefix, pf->fd);
	ft_printf_precision_print(pf);
	if (nbr || !pf->conv.to_precis ||
								pf->conv.precision >= (int)ft_strlen(c_nbr))
		pf->printed += ft_putstr_fd(c_nbr, pf->fd);
	else if (pf->conv.field_min > 0)
		pf->printed += ft_putstr_fd(" ", pf->fd);
	ft_printf_field_print(pf, RIGHT);
	free(c_nbr);
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
