/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:33:08 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/10 17:34:52 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
	#include <locale.h>

int main(int ac, char **av)
{
	setlocale(LC_ALL, "");
	int ret;
	printf("\n\n");

	ret = ft_printf("{%030S}", L"�M-M-^Q�M-^X��M-�M-^O��M-^L��M-M-^B");
	printf("\t\t%d\n", ret);

	ret = printf("{%030S}", L"�M-M-^Q�M-^X��M-�M-^O��M-^L��M-M-^B");
	printf("\t\t%d\n", ret);

	return (0);
}
