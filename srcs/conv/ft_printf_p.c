/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:52:30 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/10 12:22:58 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_p(t_printf *pf)
{
	size_t	before;

	pf->conv.chang = TRUE;
	if (pf->conv.size < 5)
		pf->conv.size = 5;
	before = pf->printed;
	ft_printf_xxx(pf, "0123456789abcdef", "0x", 1);
	return (EXIT_SUCCESS);
}
