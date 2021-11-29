#include "printf.h"
#include <stdio.h>
int	main()
{
	char c = 'f';
	char	str[100] = "chou-fleur";
	char	s[100] = "crevette";
	int	nb = -90;
	unsigned int nbr = -90;
	printf("\n%i", ft_printf("chou %s %c %s %% %i %u", str, c, s, nb, nbr));
	printf("\n%i", printf("chou %s %c %s %% %i %u", str, c, s, nb, nbr));
	return (0);
}