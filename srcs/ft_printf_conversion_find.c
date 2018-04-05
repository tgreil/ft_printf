/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_find.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:28 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/05 15:36:56 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_conversion_find(t_printf *pf, char conv_c)
{
	if (conv_c == 'A')
		return (ft_printf_a(pf));
	else if (conv_c == 'a')
		return (ft_printf_a(pf));
	else if (conv_c == 'b')
		return (ft_printf_b(pf));
	else if (conv_c == 'c')
		return (ft_printf_c(pf));
	else if (conv_c == 'C')
		return (ft_printf_cc(pf));
	else if (conv_c == 'd')
		return (ft_printf_d(pf));
	else if (conv_c == 's')
		return (ft_printf_s(pf));
	else if (conv_c == 'S')
		return (ft_printf_ss(pf));
	return (EXIT_ERROR);
}
