/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:55 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 13:44:10 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_printf_type_get(t_printf *pf, char type)
{
	long long	nbr;

	if (type == 1)
		nbr = (short)va_arg(pf->ap, int);
	else if (type == 2)
		nbr = (char)va_arg(pf->ap, int);
	else if (type == 3)
		nbr = va_arg(pf->ap, unsigned int);
	else if (type == 5)
		nbr = va_arg(pf->ap, long);
	else if (type == 6)
		nbr = va_arg(pf->ap, long long);
	else
		nbr = va_arg(pf->ap, int);
	return (nbr);
}
