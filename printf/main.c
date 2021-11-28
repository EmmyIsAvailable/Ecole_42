#include "printf.h"
#include <stdio.h>
int	main()
{
	char c = 'f';
	char	str[100] = "chou-fleur";
	ft_printf("chou %s %c", str, c);
	return (0);
}