#include "pipex.h"

void	arg_to_data(int ac, char **av, char **envp)
{
	data->ac = ac;
	data->av = av;
	data->envp = envp;
	data->infile = 0;
	data->outfile = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	arg_to_data(ac, av, envp);
	if (ac != 5)
	{
		ft_putstr_fd("Format : ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (-1);
	}
	if (ac == 5)
	{
		data.infile = open(av[1], O_RDONLY, 644);
		data.outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 644);
		if (data.infile < 0 || data.outfile < 0)
			return (-1);
		pipex(f1, f2, av, envp);
	}
	return (0);
}
