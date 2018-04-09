/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_find.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:28 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 14:26:21 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_conversion_find2(t_printf *pf, char conv_c)
{
	if (conv_c == 'G')
		return (ft_printf_gg(pf));
	else if (conv_c == 'n')
		return (ft_printf_n(pf));
	else if (conv_c == 'o')
		return (ft_printf_o(pf));
	else if (conv_c == 'O')
		return (ft_printf_oo(pf));
	else if (conv_c == 'p')
		return (ft_printf_p(pf));
	else if (conv_c == 's')
		return (ft_printf_s(pf));
	else if (conv_c == 'S')
		return (ft_printf_ss(pf));
	else if (conv_c == 'u')
		return (ft_printf_u(pf));
	else if (conv_c == 'U')
		return (ft_printf_uu(pf));
	else if (conv_c == 'x')
		return (ft_printf_x(pf));
	else if (conv_c == 'X')
		return (ft_printf_xx(pf));
	else if (conv_c == '%')
		return (ft_printf_mod(pf));
	return (EXIT_ERROR);
}

int		ft_printf_conversion_find(t_printf *pf, char conv_c)
{
	if (conv_c == 'a')
		return (ft_printf_a(pf));
	else if (conv_c == 'A')
		return (ft_printf_aa(pf));
	else if (conv_c == 'b')
		return (ft_printf_b(pf));
	else if (conv_c == 'c')
		return (ft_printf_c(pf));
	else if (conv_c == 'C')
		return (ft_printf_cc(pf));
	else if (conv_c == 'd' || conv_c == 'i')
		return (ft_printf_d(pf));
	else if (conv_c == 'D')
		return (ft_printf_dd(pf));
	else if (conv_c == 'e')
		return (ft_printf_e(pf));
	else if (conv_c == 'E')
		return (ft_printf_ee(pf));
	else if (conv_c == 'f')
		return (ft_printf_f(pf));
	else if (conv_c == 'F')
		return (ft_printf_ff(pf));
	else if (conv_c == 'g')
		return (ft_printf_g(pf));
	return (ft_printf_conversion_find2(pf, conv_c));
}
