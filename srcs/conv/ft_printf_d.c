/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:36 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 13:56:12 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_dd(t_printf *pf)
{
	pf += 1;
	return (EXIT_SUCCESS);
}

int		ft_printf_d(t_printf *pf)
{
	pf += 1;
	return (EXIT_SUCCESS);
}

int		ft_printf_i(t_printf *pf)
{
	return (ft_printf_d(pf));
}
