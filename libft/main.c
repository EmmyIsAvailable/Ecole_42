#include <stdio.h>

int	main()
{
	int	a = 97;
	int	A = 65;
	int	zero = 48;
	int	pt_excl = 33;
	int	tab = 9;
	int	delete = 127;
	printf("a : %d\nA : %d\nzero : %d\npt_excl : %d\ntab : %d\ndelete : %d\n", ft_isalpha(a), ft_isalpha(A), ft_isalpha(zero), ft_isalpha(pt_excl), ft_isalpha(tab), ft_isalpha(delete));
}