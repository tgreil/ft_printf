/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:50 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/10 16:19:33 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fill(t_printf *pf, char *str, char fill_c, char side)
{
	int	str_size;
	int	i;

	i = 0;
	str_size = 0;
	while (str[str_size])
		str_size++;
	while (side == LEFT && i + str_size < pf->conv.field_min)
	{
		pf->printed += ft_putchar_fd(fill_c, pf->fd);
		i++;
	}
	pf->printed += ft_putstr_fd(str, pf->fd);
	i += str_size;
	while (side == RIGHT && i < pf->conv.field_min)
	{
		pf->printed += ft_putchar_fd(' ', pf->fd);
		i++;
	}
}

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t	printed;
	size_t	i;

	i = 0;
	printed = 0;
	while (str[i])
	{
		printed += ft_putchar_fd(str[i], fd);
		i++;
	}
	return (printed);
}

int		ft_putchar_fd(int c, int fd)
{
	return (write(fd, &c, 1));
}
