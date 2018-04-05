/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llong_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:31:42 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/05 15:31:44 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_itoa_getsize(unsigned long long nb, size_t base_len)
{
	int	size;

	size = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		size++;
		nb = nb / base_len;
	}
	return (size);
}

char		*ft_llong_itoa(unsigned long long nb, char *base)
{
	char	*new;
	size_t	base_len;
	size_t	len;
	size_t	i;

	if (nb == ULLONG_MAX)
		return (ft_strdup("18446744073709551615"));
	base_len = ft_strlen(base);
	len = ft_itoa_getsize(nb, base_len);
	if (!(new = malloc(len + 1)))
		return (NULL);
	i = 0;
	new[len] = '\0';
	while (i < len)
	{
		new[len - 1] = base[nb % base_len];
		nb = nb / base_len;
		len--;
	}
	return (new);
}
