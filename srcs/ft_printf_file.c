/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:32:46 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/05 15:32:48 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_file_open(t_printf *pf, char *file_name)
{
	int	fd;

	if (!file_name)
		return (EXIT_ERROR);
	if ((fd = open(file_name, O_RDWR | O_APPEND)) < 0)
		return (EXIT_ERROR);
	if (pf->is_file == TRUE)
		close(pf->fd);
	pf->fd = fd;
	pf->is_file = TRUE;
	return (EXIT_SUCCESS);
}

int			ft_printf_file(t_printf *pf)
{
	char	*file_name;
	size_t	i;

	i = pf->i + 1;
	while (pf->str[i] && pf->str[i] != FILE_CHAR)
		i++;
	if (pf->str[i])
	{
		if (i - pf->i == 2 && pf->str[pf->i + 1] == GET_ATTR_CHAR &&
			ft_printf_file_open(pf, va_arg(pf->ap, char *)) == EXIT_S)
			pf->i = i;
		else
		{
			file_name = ft_strndup(pf->str + pf->i + 1, i - pf->i - 1);
			if (ft_printf_file_open(pf, file_name) == EXIT_S)
				pf->i = i;
			free(file_name);
		}
	}
	if (pf->is_file == FALSE)
		pf->printed += ft_putchar_fd(pf->str[pf->i], pf->fd);
	return (EXIT_SUCCESS);
}
