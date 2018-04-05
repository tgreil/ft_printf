/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:18:16 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/05 15:11:56 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_error(char *base)
{
	int	i;
	int	n;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		n = 0;
		while (base[n])
		{
			if (i != n && base[i] == base[n])
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

int			ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int		base_size;
	int		printed;

	printed = 0;
	if (!base || is_error(base))
		return (0);
	if ((base_size = ft_strlen(base)) < 2)
		return (0);
	if ((nbr < 0 ? -nbr : nbr) < base_size && nbr != INT_MIN)
	{
		if (nbr < 0)
			printed += ft_putchar_fd('-', fd);
		printed += ft_putchar_fd(base[(nbr < 0 ? -nbr : nbr)], fd);
	}
	else
	{
		printed = ft_putnbr_base_fd(nbr / base_size, base, fd);
		nbr = nbr % base_size;
		printed += ft_putchar_fd(base[nbr < 0 ? -nbr : nbr], fd);
	}
	return (printed);
}
