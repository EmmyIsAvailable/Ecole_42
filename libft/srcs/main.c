#include "libft.h"
#include <string.h>

char	f(unsigned int i, char c)
{
	if (i >= 0)
		c -= 32;
	return (c);
}

int	main(int ac, char **av)
{
	(void)ac;
	/*(void)av;*/
	int	i = 0;
	int	a = 97;
	int	A = 65;
	int	zero = 48;
	int	pt_excl = 33;
	int	tab = 9;
	int	del = 127;
	const char *test = "  	 -89u7";
	const char *oui = " j'aime ";
	const char *non = "le*poulet*au*curry";
	/*
	printf("a : %d\nA : %d\nzero : %d\npt_excl : %d\ntab : %d\ndelete : %d\n", ft_isalpha(a), ft_isalpha(A), ft_isalpha(zero), ft_isalpha(pt_excl), ft_isalpha(tab), ft_isalpha(del));
	printf("%lu\n", ft_strlen(oui));
	printf("%d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
	printf("a : %d\nA : %d\n", ft_toupper(a), ft_toupper(A));
	printf("%d\n", ft_atoi(test));
	printf("%s\n", ft_memset(av[1], atoi(av[2]), atoi(av[3])));
	printf("%s", memset(av[1], atoi(av[2]), atoi(av[3])));
	printf("%s\n%s", ft_memcpy(av[1], "", atoi(av[2])), memcpy(av[1], "", atoi(av[2])));
	char oui[100] = "je suis une choucroute";
	printf("moi : %s\nvrai : %s", ft_memmove(oui+5, oui, 11), memmove(oui+5, oui, 11));
	printf("moi : %s\nvrai : %s", ft_strchr(av[1], atoi(av[2])), strchr(av[1], atoi(av[2])));
	printf("moi : %s\nvrai : %s", ft_strrchr(av[1], atoi(av[2])), strrchr(av[1], atoi(av[2])));
	printf("moi : %s\nvrai : %s", ft_strnstr(av[1], av[2], atoi(av[3])), strnstr(av[1], av[2], atoi(av[3]));
	printf("moi : %s\nvrai : %s", ft_memchr(av[1], atoi(av[2]), atoi(av[3])), memchr(av[1], atoi(av[2]), atoi(av[3])));
	printf("moi : %d\nvrai : %d", ft_memcmp(av[1], av[2], atoi(av[3])), memcmp(av[1], av[2], atoi(av[3])));
	
	char *ptr;
	ptr = calloc(10, sizeof(char));
	if (ptr == NULL)
		return (0);
	while (i < 10)
	{
		ptr[i] = i + 65;
		printf("%c", ptr[i]);
		i++;
	}
	printf("%s", ptr);
	free(ptr);
	printf("moi : %s\nvrai : %s", ft_strdup(av[1]), strdup(av[1]));
	printf("moi : %s\n", ft_strjoin(oui, non));
	printf("%s\n", ft_substr(non, 3, 6));
	char	**tableau;
	tableau = ft_split(non, ' ');
	while (tableau[i])
	{
		printf("%s\n", tableau[i]);
		i++;
	}
	printf("%s", ft_strtrim(oui, " "));
	printf("%s", ft_itoa(-4136));
	printf("%s", ft_strmapi(non, f));
	ft_putchar_fd('o', 1);
	ft_putstr_fd("patouille la citrouille", 1);
	ft_putendl_fd("libellule chenille", 1);
	ft_putnbr_fd(-67, 1);*/
	return(0);
}