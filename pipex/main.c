#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	f1;
	int	f2;

	if (ac == 5)
	{
		f1 = open(av[1], O_RDONLY);
		f2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 644);
		if (f1 < 0 || f2 < 0)
			return (-1);
		pipex(f1, f2, av, envp);
	}
	return (0);
}
