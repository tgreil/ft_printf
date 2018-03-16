#include "ft_printf.h"

static size_t	ft_super_itoa_size(long long nbr, char *base)
{
	size_t	size;
	size_t	base_len;

	size = 0;
	if (nbr < 0)
		nbr *= -1;
	base_len = ft_strlen(base);
	while (nbr > 0 || !size)
	{
		nbr = nbr / base_len;
		size++;
	}
	return (size + 2);
}

char			*ft_super_itoa(long long nbr, char *base, size_t size_min)
{
	size_t	base_len;
	char	*new;
	size_t	size;

	size = ft_super_itoa_size(nbr, base);
	size = size < size_min ? size_min : size;
	if (!(new = malloc(sizeof(char) * size)))
		return (NULL);
	base_len = ft_strlen(base);
	new[--size] = '\0';
	if (nbr < 0)
		new[0] = '-';
	else
		new[0] = ' ';
	nbr = ABS(nbr);
	while (--size)
	{
		new[size] = base[nbr % base_len];
		nbr = nbr / base_len;
	}
	return (new);
}
