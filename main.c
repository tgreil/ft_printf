/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:33:08 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/09 19:20:19 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int main(int ac, char **av)
{
	int ret;
	ft_printf("\n\n");
	ret = ft_printf("%jx", -4294967296);
	ft_printf("\t\t%d\n", ret);
	ret = printf("%jx", -4294967296);
	printf("\t\t%d\n", ret);

	return (0);
}
