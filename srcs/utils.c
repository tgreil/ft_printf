/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:33:04 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/05 15:33:39 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(char *src)
{
	char	*new;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	if (!(new = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t		ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char		*ft_strndup(char *str, size_t n)
{
	char	*new;
	size_t	i;

	i = 0;
	while (i < n && str[i])
		i++;
	if (!(new = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int			ft_little_atoi(char *str)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb);
}

int			ft_print_char_xtime(char c, int nbr, int fd)
{
	int	printed;
	int	i;

	i = 0;
	printed = 0;
	while (i < nbr)
	{
		printed += ft_putchar_fd(c, fd);
		i++;
	}
	return (printed);
}
