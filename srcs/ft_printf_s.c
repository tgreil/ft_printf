/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:22:32 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/05 15:34:08 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_ss(t_printf *pf)
{
	char	*s;

	s = va_arg(pf->ap, char *);
	ft_printf_field(pf, s, 0, LEFT);
	pf->printed += ft_putstr_fd(s, pf->fd);
	ft_printf_field(pf, s, 0, RIGHT);
	return (EXIT_SUCCESS);
}

int		ft_printf_s(t_printf *pf)
{
	char	*s;

	s = va_arg(pf->ap, char *);
	ft_printf_field(pf, s, 0, LEFT);
	pf->printed += ft_putstr_fd(s, pf->fd);
	ft_printf_field(pf, s, 0, RIGHT);
	return (EXIT_SUCCESS);
}
