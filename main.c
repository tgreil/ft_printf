#include "ft_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	printf("%p\n", av);
	ft_printf("%d\n", av);
	//ft_printf("%s%d%s\n", "ahah :", 8, "test");
	return (0);
}
