#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	char	**envp;
	char	**av;
	int	ac;
	int	outfile;
	int	infile;
	int	fd[2];
}	t_data;

void	pipex(t_data *data);
void	ft_error(char *str);

#endif
