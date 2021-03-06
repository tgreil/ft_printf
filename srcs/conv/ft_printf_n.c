/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:03:01 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 14:47:07 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_n(t_printf *pf)
{
	int *n;

	n = va_arg(pf->ap, int *);
	if (n)
		*n = pf->printed;
	return (EXIT_SUCCESS);
}
