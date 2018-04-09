/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:31:50 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 13:49:02 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_aaa(t_printf *pf, char x, char p)
{
	pf += x + p;
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
