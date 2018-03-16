#include "ft_printf.h"
#include <stdio.h>


int main()
{
//	for(int i = 0;i < 8*8;i++)
	//{
	//	printf("%d", ((float)test) >> i & 1);
	//}
	printf("% .5d\n", 225);
	ft_printf("% .5d\n", 225);
	return (0);
}
