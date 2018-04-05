/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:15 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/05 15:36:32 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_cc(t_printf *pf)
{
	char	buf[2];

	buf[0] = (char)va_arg(pf->ap, int);
	buf[1] = '\0';
	ft_printf_field(pf, buf, 0, LEFT);
	pf->printed += ft_putchar_fd(buf[0], pf->fd);
	ft_printf_field(pf, buf, 0, RIGHT);
	return (EXIT_SUCCESS);
}

int		ft_printf_c(t_printf *pf)
{
	char	buf[2];

	buf[0] = (char)va_arg(pf->ap, int);
	buf[1] = '\0';
	ft_printf_field(pf, buf, 0, LEFT);
	pf->printed += ft_putchar_fd(buf[0], pf->fd);
	ft_printf_field(pf, buf, 0, RIGHT);
	return (EXIT_SUCCESS);
}
