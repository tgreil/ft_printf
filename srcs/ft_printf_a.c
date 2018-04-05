/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:31:50 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/05 15:39:10 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_aaa(t_printf *pf, char x, char p)
{
	double	val;
	int		val_pow;

	val_pow = 1;
	val = va_arg(pf->ap, double);
	pf->printed += ft_putchar_fd('0', pf->fd);
	pf->printed += ft_putchar_fd(x, pf->fd);

	pf->printed += ft_putnbr_base_fd((long long)val_pow, "01234567", pf->fd);

	pf->printed += ft_putchar_fd(p, pf->fd);
	pf->printed += ft_putchar_fd('+', pf->fd);
	pf->printed += ft_putnbr_base_fd(val_pow, "0123456789", pf->fd);
	return (EXIT_SUCCESS);
}

int	ft_printf_aa(t_printf *pf)
{
	return (ft_printf_aaa(pf, 'X', 'P'));
}

int	ft_printf_a(t_printf *pf)
{
	return (ft_printf_aaa(pf, 'x', 'p'));
}
