/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:15 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 17:43:35 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_cc(t_printf *pf)
{
	pf += 1;
	return (EXIT_SUCCESS);
}

int		ft_printf_c(t_printf *pf)
{
	char	c[2];

	c[0] = (char)va_arg(pf->ap, int);
	c[1] = '\0';
	pf->conv.to_sign = FALSE;
	pf->conv.precision = 0;
	ft_printf_field_calc(pf, 1, c, NULL);
	if (!c[0] && pf->conv.field_min)
		pf->conv.field_min--;
	ft_printf_field_print(pf, LEFT);
	pf->printed += ft_putchar_fd(c[0], pf->fd);
	ft_printf_field_print(pf, RIGHT);
	return (EXIT_SUCCESS);
}
