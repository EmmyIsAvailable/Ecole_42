#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	/*(void)ac;*/
	/*(void)av;*/
	int	a = 97;
	int	A = 65;
	int	zero = 48;
	int	pt_excl = 33;
	int	tab = 9;
	int	delete = 127;
	/*printf("a : %d\nA : %d\nzero : %d\npt_excl : %d\ntab : %d\ndelete : %d\n", ft_isalpha(a), ft_isalpha(A), ft_isalpha(zero), ft_isalpha(pt_excl), ft_isalpha(tab), ft_isalpha(delete));*/
	/*printf("%ld\n", ft_strlen("coucou"));*/
	printf("%d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
}