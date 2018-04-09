/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:28:14 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 13:49:45 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_xxx(t_printf *pf, char *base, char *prefix)
{
	pf += 1;
	base += 1;
	prefix += 1;
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
