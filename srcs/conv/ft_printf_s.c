/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:22:32 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/10 17:33:21 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr(t_printf *pf, int *s, int s_len)
{
	int		ret;

	while (s_len > 0)
	{
		ret = ft_putwchar_fd(*s, pf->fd);
		pf->printed += ret;
		s_len--;
		s++;
	}
}

int		ft_printf_ss(t_printf *pf)
{
	int		s_len;
	int		*s;

	if (pf->conv.precision < 0)
		pf->conv.precision *= -1;
	s = va_arg(pf->ap, int *);
	if (s)
	{
		s_len = 0;
		while (s[s_len])
			s_len++;
	}
	else
		s_len = ft_strlen(PRINT_NULL);
	if (pf->conv.to_precis && s_len > pf->conv.precision)
		s_len = pf->conv.precision;
	pf->conv.field_min -= s_len;
	ft_printf_field_print(pf, LEFT);
	if (s && s_len > 0)
		ft_putwstr(pf, s, s_len);
	else if (s_len > 0)
		pf->printed += write(pf->fd, PRINT_NULL, s_len);
	ft_printf_field_print(pf, RIGHT);
	return (EXIT_SUCCESS);
}

int		ft_printf_s(t_printf *pf)
{
	int		s_len;
	char	*s;

	if (pf->conv.size >= 5)
		return (ft_printf_ss(pf));
	if (pf->conv.precision < 0)
		pf->conv.precision *= -1;
	s = va_arg(pf->ap, char *);
	if (s)
		s_len = ft_strlen(s);
	else
		s_len = ft_strlen(PRINT_NULL);
	if (pf->conv.to_precis && s_len > pf->conv.precision)
		s_len = pf->conv.precision;
	pf->conv.field_min -= s_len;
	ft_printf_field_print(pf, LEFT);
	if (s && s_len > 0)
		pf->printed += write(pf->fd, s, s_len);
	else if (s_len > 0)
		pf->printed += write(pf->fd, PRINT_NULL, s_len);
	ft_printf_field_print(pf, RIGHT);
	return (EXIT_SUCCESS);
}
