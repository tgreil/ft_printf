/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:22:32 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 18:03:41 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_ss(t_printf *pf)
{
	ft_printf_s(pf);
	return (EXIT_SUCCESS);
}

int		ft_printf_s(t_printf *pf)
{
	int		s_len;
	char	*s;

	s = va_arg(pf->ap, char *);
	if (s)
		s_len = ft_strlen(s);
	else
		s_len = ft_strlen(PRINT_NULL);
	if (pf->conv.precision && s_len)
		s_len = pf->conv.precision;
	pf->conv.field_min -= s_len;
	ft_printf_field_print(pf, LEFT);
	if (s && s_len > 0)
		pf->printed += write(pf->fd, s, s_len);
	else if (s_len > 0)
		pf->printed += write(pf->fd, PRINT_NULL, s_len);
	ft_printf_field_print(pf, RIGHT);
	return (EXIT_SUCCESS);
}
