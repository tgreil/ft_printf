#include "ft_printf.h"

static int	ft_itoa_getsize(unsigned long long nb, char is_neg)
{
	int	size;

	size = 0;
	if (!nb)
		return (1);
	if (is_neg)
		size++;
	while (nb)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

char		*ft_itoa(unsigned long long nb, char is_neg)
{
	char	*new;
	size_t	len;
	size_t	i;

	if (nb == ULLONG_MAX)
		return (ft_strdup("18446744073709551615"));
	len = ft_itoa_getsize(nb, is_neg);
	if (!(new = malloc(len + 1)))
		return (NULL);
	i = 0;
	if (is_neg)
		new[i++] = '-';
	new[len] = '\0';
	while (i < len)
	{
		new[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (new);
}
