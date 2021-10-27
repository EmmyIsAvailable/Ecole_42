#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char **av)
{
	(void)ac;
	/*(void)av;*/
	int	a = 97;
	int	A = 65;
	int	zero = 48;
	int	pt_excl = 33;
	int	tab = 9;
	int	delete = 127;
	const char *test = "  	 -89u7";
	/*
	printf("a : %d\nA : %d\nzero : %d\npt_excl : %d\ntab : %d\ndelete : %d\n", ft_isalpha(a), ft_isalpha(A), ft_isalpha(zero), ft_isalpha(pt_excl), ft_isalpha(tab), ft_isalpha(delete));
	printf("%ld\n", ft_strlen("coucou"));
	printf("%d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
	printf("a : %d\nA : %d\n", ft_toupper(a), ft_toupper(A));
	printf("%d\n", ft_atoi(test));
	printf("%s\n", ft_memset(av[1], atoi(av[2]), atoi(av[3])));
	printf("%s", memset(av[1], atoi(av[2]), atoi(av[3])));
	*/
	return(0);
}