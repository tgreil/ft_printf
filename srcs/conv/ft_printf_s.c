/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:22:32 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 15:29:03 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_ss(t_printf *pf)
{
	pf += 1;
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
	pf->conv.field_min -= s_len;
	ft_printf_field_print(pf, LEFT);
	if (s)
		pf->printed += ft_putstr_fd(s, pf->fd);
	else
		pf->printed += ft_putstr_fd(PRINT_NULL, pf->fd);
	ft_printf_field_print(pf, RIGHT);
	return (EXIT_SUCCESS);
}
