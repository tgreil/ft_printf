/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:55 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/05 15:32:56 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_sign(t_printf *pf, char is_neg)
{
	if (is_neg)
		pf->printed += ft_putchar_fd('-', pf->fd);
	else if (pf->conv.to_sign)
		pf->printed += ft_putchar_fd('+', pf->fd);
}

void		ft_printf_field(t_printf *pf, char *c_nbr, char is_neg, char side)
{
	size_t	len;
	size_t	i;
	int		x;

	i = 0;
	len = 0;
	while (c_nbr[len])
		len++;
	x = pf->conv.field_min - len;
	if (is_neg || pf->conv.to_sign)
		x--;
	if ((pf->conv.field_fill_side == LEFT || pf->conv.field_fill_char != ' ')
			&& side == LEFT)
		pf->printed += ft_print_char_xtime(pf->conv.field_fill_char, x, pf->fd);
	else if (pf->conv.field_fill_side == RIGHT && side == RIGHT)
		pf->printed += ft_print_char_xtime(' ', x, pf->fd);
}
