/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:08:40 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/12 15:33:05 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	**ft_free_tab(char **data)
{
	int	i;

	i = -1;
	while (data[++i])
	{
		free(data[i]);
		data[i] = NULL;
	}
	return (NULL);
}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

t_data	arg_to_data(int ac, char **av, char **envp)
{
	t_data	tmp;

	tmp.ac = ac;
	tmp.av = av;
	tmp.envp = envp;
	tmp.infile = 0;
	tmp.outfile = 0;
	return (tmp);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		i;

	i = 1;
	data = arg_to_data(ac, av, envp);
	if (ac < 5)
	{
		ft_putstr_fd("Format : ./pipex file1 cmd1 ... cmdn file2\n", 2);
		exit (1);
	}
	else
	{
		data.infile = open(av[1], O_RDONLY);
		data.outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data.infile < 0 || data.outfile < 0)
			ft_error("Error : open infile or outfile failed\n");
		while (++i < data.ac - 2)
			pipex(&data, av[i], av[i + 1]);
	}
	return (0);
}
