#include "ft_printf.h"
#include <stdio.h>

/*  (%) (flag) (valeur min de champ) ((.)valeur de precision) (modificateur de longueur) (conversion)  */
/*  (*) -> reclame argument       */
/*  $ <- index va_arg   ==> list chainé ?   */

int main()
{
	int printed = ft_printf("test $*$ test\n", "test");
	printf("\nprinted:\t%d\n", printed);
	return (0);
}
